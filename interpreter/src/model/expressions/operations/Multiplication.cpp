//
// Created by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Multiplication.h"

namespace naylang {
Multiplication::Multiplication(std::shared_ptr<Expression> lexp, std::shared_ptr<Expression> rexp) {
    _leftOperand = std::move(lexp);
    _rightOperand = std::move(rexp);
}

void Multiplication::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

std::shared_ptr<Expression> Multiplication::leftOperand() const {
    return _leftOperand;
}

std::shared_ptr<Expression> Multiplication::rightOperand() const {
    return _rightOperand;
}
}