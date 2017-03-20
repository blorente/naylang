//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "ExecutionEvaluator.h"

#include <model/execution/objects/GraceBoolean.h>
#include <model/ast/expressions/primitives/BooleanLiteral.h>

namespace naylang {

void ExecutionEvaluator::evaluate(BooleanLiteral &expression) {
    _partial = make_obj<GraceBoolean>(expression.value());
}

void ExecutionEvaluator::evaluate(ImplicitRequestNode &expression) {
//    expression.params()[0]->accept(*this);
//    GraceObjectPtr self = _partial;

    std::vector<GraceObjectPtr> paramValues;
    for (auto param : expression.params()) {
        param->accept(*this);
        paramValues.push_back(_partial);
    }
    GraceObjectPtr ret = _currentScope->dispatch(expression.identifier(), *this, paramValues);
    // ret might be GraceDone
    _partial = ret;
}

void ExecutionEvaluator::evaluate(MethodDeclaration &expression) {
    MethodPtr method = make_meth(expression.body());
    _currentScope->addMethod(expression.name(), method);
}

ExecutionEvaluator::ExecutionEvaluator() : _currentScope{make_obj<GraceScope>()}, _partial{GraceDone}{}

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
    GraceObjectPtr self = _partial;

    std::vector<GraceObjectPtr> paramValues;
    for (auto param : expression.params()) {
        param->accept(*this);
        paramValues.push_back(_partial);
    }
    GraceObjectPtr ret = self->dispatch(expression.identifier(), *this, paramValues);
    // ret might be GraceDone
    _partial = ret;
}
}