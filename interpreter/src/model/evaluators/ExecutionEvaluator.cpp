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
    expression.params()[0]->accept(*this);
    GraceObjectPtr self = _partial;

    std::vector<GraceObjectPtr> paramValues;
    for (int i = 1; i < expression.params().size(); i++) {
        expression.params()[i]->accept(*this);
        paramValues.push_back(_partial);
    }
    // A this point, all the parameters are in the stack
    GraceObjectPtr ret = self->dispatch(expression.identifier(), *this, paramValues);
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
}