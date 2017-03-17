//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "ExecutionEvaluator.h"

#include <model/execution/objects/GraceBoolean.h>
#include <model/execution/objects/GraceObjectFactory.h>

#include <model/ast/expressions/primitives/BooleanLiteral.h>

namespace naylang {

const std::stack<GraceObjectPtr> &ExecutionEvaluator::objectStack() const {
    return _objStack;
}

void ExecutionEvaluator::evaluate(BooleanLiteral &expression) {
    _objStack.push(make_obj<GraceBoolean>(expression.value()));
}

void ExecutionEvaluator::evaluate(RequestNode &expression) {
    expression.params()[0]->accept(*this);
    GraceObjectPtr self = std::move(_objStack.top());
    _objStack.pop();

    for (int i = 1; i < expression.params().size(); i++) {
        expression.params()[i]->accept(*this);
    }
    // A this point, all the parameters are in the stack
    GraceObjectPtr ret = self->dispatch(expression.identifier(), *this);
    // ret might be GraceDone
    _objStack.push(ret);
}
}