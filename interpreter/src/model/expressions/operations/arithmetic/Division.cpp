//
// Created by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Division.h"

namespace naylang {
Division::Division(ExpressionPtr numerator, ExpressionPtr denominator) {
    _numerator = std::move(numerator);
    _denominator = std::move(denominator);
}

void Division::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

ExpressionPtr Division::numerator() const {
    return _numerator;
}

ExpressionPtr Division::denominator() const {
    return _denominator;
}

ExpressionPtr Division::leftOperand() const {
    return numerator();
}

ExpressionPtr Division::rightOperand() const {
    return denominator();
}
}