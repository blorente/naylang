//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include <iostream>
#include "GraceEvaluator.h"

namespace naylang {

double GraceEvaluator::getPartial() const {
    return _partial;
}

void GraceEvaluator::evaluate(Number &expression) {
    _partial = expression.value();
}

void GraceEvaluator::evaluate(Constant &expression) {
    expression.value()->accept(*this);
    auto partial = Value(_partial);
    _environment.bind(expression.identifier(), partial);
}

void GraceEvaluator::evaluate(Assignment &expression) {
    expression.value()->accept(*this);
    auto partial = Value(_partial);
    _environment.change(expression.identifier(), partial);
}

void GraceEvaluator::evaluate(Addition &expression) {
    expression.leftOperand()->accept(*this);
    auto lop = _partial;
    expression.rightOperand()->accept(*this);
    auto rop = _partial;
    _partial = lop + rop;
}


void GraceEvaluator::evaluate(VariableDeclaration &expression) {
    _environment.bind(expression.identifier(), INVALID_VALUE);
}

void GraceEvaluator::evaluate(VariableReference &expression) {
    if (_environment.get(expression.identifier()) == INVALID_VALUE) {
        throw "Variable not initialized";
    }
    double currentValue = _environment.get(expression.identifier()).value();
    _partial = currentValue;
}

void GraceEvaluator::evaluate(Subtraction &expression) {
    expression.leftOperand()->accept(*this);
    auto lop = _partial;
    expression.rightOperand()->accept(*this);
    auto rop = _partial;
    _partial = lop - rop;
}

void GraceEvaluator::evaluate(Multiplication &expression) {
    expression.leftOperand()->accept(*this);
    auto lop = _partial;
    expression.rightOperand()->accept(*this);
    auto rop = _partial;
    _partial = lop * rop;
}

void GraceEvaluator::evaluate(Division &expression) {
    expression.numerator()->accept(*this);
    auto numerator = _partial;
    expression.denominator()->accept(*this);
    auto denominator = _partial;
    if (denominator == 0.0) {
        throw "Division by zero";
    }
    _partial = numerator / denominator;
}

}
