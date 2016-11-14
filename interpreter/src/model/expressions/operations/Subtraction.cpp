//
// Created by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Subtraction.h"

namespace naylang {
Subtraction::Subtraction(std::shared_ptr<Expression> lexp, std::shared_ptr<Expression> rexp) {
    _leftOperand = std::move(lexp);
    _rightOperand = std::move(rexp);
}

void Subtraction::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

std::shared_ptr<Expression> Subtraction::leftOperand() const {
    return _leftOperand;
}

std::shared_ptr<Expression> Subtraction::rightOperand() const {
    return _rightOperand;
}
}