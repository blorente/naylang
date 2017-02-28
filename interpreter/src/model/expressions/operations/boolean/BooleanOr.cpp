//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "BooleanOr.h"

namespace naylang {

BooleanOr::BooleanOr(ExpressionPtr lexp, ExpressionPtr rexp)  {
    _leftOperand = std::move(lexp);
    _rightOperand = std::move(rexp);
}

void BooleanOr::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

ExpressionPtr BooleanOr::leftOperand() const {
    return _leftOperand;
}

ExpressionPtr BooleanOr::rightOperand() const {
    return _rightOperand;
}
}