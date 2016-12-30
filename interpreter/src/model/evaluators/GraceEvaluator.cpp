//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include <iostream>
#include "GraceEvaluator.h"

namespace naylang {

double GraceEvaluator::getPartialDouble() const {
    return _partialDouble;
}

bool GraceEvaluator::getPartialBool() const {
    return _partialBool;
}

void GraceEvaluator::evaluate(Number &expression) {
    _partialDouble = expression.value();
}

void GraceEvaluator::evaluate(Boolean &expression) {
    _partialBool = expression.value();
}

void GraceEvaluator::evaluate(Constant &expression) {
    expression.value()->accept(*this);
    auto partial = Value(_partialDouble);
    _environment.bind(expression.identifier(), partial);
}

void GraceEvaluator::evaluate(Assignment &expression) {
    expression.value()->accept(*this);
    auto partial = Value(_partialDouble);
    _environment.change(expression.identifier(), partial);
}

void GraceEvaluator::evaluate(Addition &expression) {
    expression.leftOperand()->accept(*this);
    auto lop = _partialDouble;
    expression.rightOperand()->accept(*this);
    auto rop = _partialDouble;
    _partialDouble = lop + rop;
}


void GraceEvaluator::evaluate(VariableDeclaration &expression) {
    _environment.bind(expression.identifier(), INVALID_VALUE);
}

void GraceEvaluator::evaluate(VariableReference &expression) {
    if (_environment.get(expression.identifier()) == INVALID_VALUE) {
        throw "Variable not initialized";
    }
    double currentValue = _environment.get(expression.identifier()).value();
    _partialDouble = currentValue;
}

void GraceEvaluator::evaluate(IfThenElse &expression) {
    expression.condition()->accept(*this);
    auto condition = _partialBool;
    if (condition) {
        expression.thenExpression()->accept(*this);
    } else {
        expression.elseExpression()->accept(*this);
    }
}

void GraceEvaluator::evaluate(Subtraction &expression) {
    expression.leftOperand()->accept(*this);
    auto lop = _partialDouble;
    expression.rightOperand()->accept(*this);
    auto rop = _partialDouble;
    _partialDouble = lop - rop;
}

void GraceEvaluator::evaluate(Multiplication &expression) {
    expression.leftOperand()->accept(*this);
    auto lop = _partialDouble;
    expression.rightOperand()->accept(*this);
    auto rop = _partialDouble;
    _partialDouble = lop * rop;
}

void GraceEvaluator::evaluate(Division &expression) {
    expression.numerator()->accept(*this);
    auto numerator = _partialDouble;
    expression.denominator()->accept(*this);
    auto denominator = _partialDouble;
    if (denominator == 0.0) {
        throw "Division by zero";
    }
    _partialDouble = numerator / denominator;
}
}
