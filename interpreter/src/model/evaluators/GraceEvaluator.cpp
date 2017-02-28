//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include <iostream>
#include <model/environment/GraceObjectFactory.h>
#include <model/environment/identifiers/VariableIdentifier.h>
#include <model/environment/identifiers/IdentifierFactory.h>
#include "GraceEvaluator.h"

namespace naylang {

GraceEvaluator::GraceEvaluator() {
    _environment = std::make_shared<Environment>();
}

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
    auto partial = GraceObjectFactory::createNumber(_partialDouble);
    auto identifier = IdentifierFactory::createVariableIdentifier(expression.identifier());
    _environment->bind(identifier, partial);
}

void GraceEvaluator::evaluate(Assignment &expression) {
    expression.value()->accept(*this);
    auto partial = GraceObjectFactory::createNumber(_partialDouble);
    auto identifier = IdentifierFactory::createVariableIdentifier(expression.identifier());
    _environment->change(identifier, partial);
}

void GraceEvaluator::evaluate(Addition &expression) {
    expression.leftOperand()->accept(*this);
    auto lop = _partialDouble;
    expression.rightOperand()->accept(*this);
    auto rop = _partialDouble;
    _partialDouble = lop + rop;
}

void GraceEvaluator::evaluate(VariableDeclaration &expression) {
    auto identifier = IdentifierFactory::createVariableIdentifier(expression.identifier());
    _environment->bind(identifier, GraceObjectFactory::createUndefined());
}

void GraceEvaluator::evaluate(VariableReference &expression) {
    auto identifier = IdentifierFactory::createVariableIdentifier(expression.identifier());
    if (_environment->get(identifier).isUndefined()) {
        throw "Variable not initialized";
    }
    double currentValue = _environment->get(identifier).asNumber();
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

void GraceEvaluator::evaluate(WhileLoop &expression) {
    expression.condition()->accept(*this);
    auto condition = _partialBool;
    while (condition) {
        expression.body()->accept(*this);
        expression.condition()->accept(*this);
        condition = _partialBool;
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

void GraceEvaluator::evaluate(ExpressionBlock &expression) {
    auto parentEnv = _environment;
    _environment = std::make_shared<Environment>(_environment);
    for(auto exp : expression.expressions()) {
        exp->accept(*this);
    }
    _environment = parentEnv;
}

void GraceEvaluator::evaluate(MethodDeclaration &expression) {
    GraceObject body = GraceObjectFactory::createMethod(expression.getBody());
    auto id = IdentifierFactory::createMethodIdentifier(expression.getCanonName());
    _environment->bind(id, body);
}

void GraceEvaluator::evaluate(MethodCall &expression) {
    auto parentEnv = _environment;
    _environment = std::make_shared<Environment>(_environment);

    int i = 0;
    for (auto expr : expression.getParameters()) {
        expr->accept(*this);
        auto value = GraceObject{_partialDouble};
        std::string tempstring = "temp"+ std::to_string(i);
        auto tempid = IdentifierFactory::createVariableIdentifier(tempstring);
        _environment->bind(tempid, value);
        i++;
    }
    _environment->get(IdentifierFactory::createMethodIdentifier(expression.getMethodName())).asMethod()->accept(*this);

    _environment = parentEnv;
}

void GraceEvaluator::evaluate(ParameterList &expression) {
    for (auto exp : expression.parameters()) {
        exp->accept(*this);
    }
}
}
