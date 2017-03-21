//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "ExecutionEvaluator.h"

#include <model/execution/objects/GraceBoolean.h>
#include <model/ast/expressions/primitives/BooleanLiteral.h>
#include <model/execution/objects/GraceClosure.h>

namespace naylang {

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
    MethodPtr method = make_meth(expression.body());
    _currentScope->addMethod(expression.name(), method);
}

ExecutionEvaluator::ExecutionEvaluator() : _currentScope{make_obj<GraceScope>()}, _partial{make_obj<GraceDoneDef>()}{}

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

void ExecutionEvaluator::evaluate(Block &expression) {
    _partial = make_obj<GraceClosure>();
}

void ExecutionEvaluator::setScope(GraceObjectPtr scope) {
    _currentScope = scope;
}

void ExecutionEvaluator::evaluate(VariableReference &expression) {
    if (!_currentScope->hasField(expression.identifier()))
        throw "Variable not found in scope";
    _partial = _currentScope->getField(expression.identifier());
}
}