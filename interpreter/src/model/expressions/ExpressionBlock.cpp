//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "ExpressionBlock.h"

namespace naylang {
ExpressionBlock::ExpressionBlock() {}

void ExpressionBlock::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

void ExpressionBlock::addExpression(ExpressionPtr expression) {
    _expressions.push_back(std::move(expression));
}

const std::vector<ExpressionPtr> &ExpressionBlock::expressions() const {
    return _expressions;
}
}