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

void ExpressionBlock::addExpression(std::shared_ptr<Expression> expression) {
    _expressions.push_back(std::move(expression));
}

const std::vector<std::shared_ptr<Expression>> &ExpressionBlock::expressions() const {
    return _expressions;
}
}