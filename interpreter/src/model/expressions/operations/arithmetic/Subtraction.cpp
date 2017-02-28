//
// Created by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Subtraction.h"

namespace naylang {
Subtraction::Subtraction(ExpressionPtr lexp, ExpressionPtr rexp) {
    _leftOperand = std::move(lexp);
    _rightOperand = std::move(rexp);
}

void Subtraction::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

ExpressionPtr Subtraction::leftOperand() const {
    return _leftOperand;
}

ExpressionPtr Subtraction::rightOperand() const {
    return _rightOperand;
}
}