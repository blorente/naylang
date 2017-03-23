//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "ExecutionEvaluator.h"

#include <model/execution/objects/GraceBoolean.h>
#include <model/execution/objects/GraceClosure.h>
#include <model/execution/objects/GraceScope.h>
#include <model/execution/objects/GraceDoneDef.h>
#include <model/execution/objects/UserObject.h>
#include <model/execution/objects/GraceBlock.h>

namespace naylang {

ExecutionEvaluator::ExecutionEvaluator() : _currentScope{make_obj<GraceScope>()}, _partial{make_obj<GraceDoneDef>()}{}

void ExecutionEvaluator::evaluate(BooleanLiteral &expression) {
    _partial = make_obj<GraceBoolean>(expression.value());
}

void ExecutionEvaluator::evaluate(ImplicitRequestNode &expression) {
    std::vector<GraceObjectPtr> paramValues;
    for (int i = 0; i < expression.params().size(); i++) {
        expression.params()[i]->accept(*this);
        paramValues.push_back(_partial);
    }

    _partial = _currentScope->dispatch(expression.identifier(), *this, paramValues);
}

void ExecutionEvaluator::evaluate(MethodDeclaration &expression) {
    MethodPtr method = make_meth(expression.params(), expression.body());
    _currentScope->addMethod(expression.name(), method);
}


void ExecutionEvaluator::evaluate(Return &expression) {
    return;
}

void ExecutionEvaluator::evaluate(ExplicitRequestNode &expression) {
    expression.receiver()->accept(*this);
    auto self = _partial;

    std::vector<GraceObjectPtr> paramValues;
    for (auto param : expression.params()) {
        param->accept(*this);
        paramValues.push_back(_partial);
    }
    _partial = self->dispatch(expression.identifier(), *this, paramValues);
}

void ExecutionEvaluator::evaluate(VariableReference &expression) {
    if (!_currentScope->hasField(expression.identifier()))
        throw "Variable not found in scope";
    _partial = _currentScope->getField(expression.identifier());
}

void ExecutionEvaluator::evaluate(ObjectConstructor &expression) {
    GraceObjectPtr oldScope = _currentScope;
    _currentScope = make_obj<UserObject>();
    for (auto node : expression.statements()) {
        node->accept(*this);
    }
    _partial = _currentScope;
    _currentScope = oldScope;
}

void ExecutionEvaluator::evaluate(ConstantDeclaration &expression) {
    expression.value()->accept(*this);
    _currentScope->setField(expression.name(), _partial);
}

void ExecutionEvaluator::evaluate(Block &expression) {
    auto meth = make_meth(expression.params(), expression.body());
    _partial = make_obj<GraceBlock>(meth);
}

const GraceObjectPtr &ExecutionEvaluator::partial() const {
    return _partial;
}

GraceObjectPtr ExecutionEvaluator::currentScope() const {
    return _currentScope;
}

GraceObjectPtr ExecutionEvaluator::createNewScope() {
    GraceObjectPtr newScope = make_obj<GraceScope>();
    newScope->setOuter(_currentScope);
    _currentScope = newScope;
    return newScope;
}

void ExecutionEvaluator::restoreScope() {
    _currentScope = _currentScope->outer();
}

void ExecutionEvaluator::setScope(GraceObjectPtr scope) {
    _currentScope = scope;
}
}