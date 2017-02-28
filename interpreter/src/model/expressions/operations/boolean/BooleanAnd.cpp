//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "BooleanAnd.h"

namespace naylang {

BooleanAnd::BooleanAnd(ExpressionPtr lexp, ExpressionPtr rexp)  {
    _leftOperand = std::move(lexp);
    _rightOperand = std::move(rexp);
}

void BooleanAnd::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

ExpressionPtr BooleanAnd::leftOperand() const {
    return _leftOperand;
}

ExpressionPtr BooleanAnd::rightOperand() const {
    return _rightOperand;
}
}
