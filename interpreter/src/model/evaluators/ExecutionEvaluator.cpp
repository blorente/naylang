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
}