//
// Created by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Division.h"

namespace naylang {
Division::Division(std::shared_ptr<Expression> numerator, std::shared_ptr<Expression> denominator) {
    _numerator = std::move(numerator);
    _denominator = std::move(denominator);
}

void Division::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

std::shared_ptr<Expression> Division::numerator() const {
    return _numerator;
}

std::shared_ptr<Expression> Division::denominator() const {
    return _denominator;
}

std::shared_ptr<Expression> Division::leftOperand() const {
    return numerator();
}

std::shared_ptr<Expression> Division::rightOperand() const {
    return denominator();
}
}