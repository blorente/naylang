//
// Created by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Multiplication.h"

namespace naylang {
Multiplication::Multiplication(ExpressionPtr lexp, ExpressionPtr rexp) {
    _leftOperand = std::move(lexp);
    _rightOperand = std::move(rexp);
}

void Multiplication::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

ExpressionPtr Multiplication::leftOperand() const {
    return _leftOperand;
}

ExpressionPtr Multiplication::rightOperand() const {
    return _rightOperand;
}
}