//
// Created by borja on 4/1/17.
//

#include <iostream>
#include "ASTPrintEvaluator.h"

naylang::ASTPrintEvaluator::ASTPrintEvaluator() : _indentLevel{0} {}

void naylang::ASTPrintEvaluator::evaluate(naylang::NumberLiteral &expression) {
    indent();
    std::cout << "Number: " << expression.value() << std::endl;
}

void naylang::ASTPrintEvaluator::evaluate(naylang::BooleanLiteral &expression) {
    indent();
    std::cout << "Boolean: " << expression.value() << std::endl;
}

void naylang::ASTPrintEvaluator::evaluate(naylang::CharLiteral &expression) {
    indent();
    std::cout << '\"' << expression.value() << '\"';
}

void naylang::ASTPrintEvaluator::evaluate(naylang::StringLiteral &expression) {
    indent();
    std::cout << "String: " << '\"' << expression.value() << '\"' << std::endl;
}

void naylang::ASTPrintEvaluator::evaluate(naylang::ImplicitRequestNode &expression) {
    indent();
    std::cout << "ImplicitRequest: <<" << expression.identifier()  << '(' << std::endl;
    increaseIndent();
    for (auto param : expression.params()) {
        indent();
        param->accept(*this);
        std::cout << ',' << std::endl;
    }
    decreaseIndent();
    indent();
    std::cout << ')' << std::endl;
}

void naylang::ASTPrintEvaluator::evaluate(naylang::ExplicitRequestNode &expression) {
    indent();
    std::cout << "ExplicitRequest: ";
    expression.receiver()->accept(*this);
    std::cout << '.' << expression.identifier()  << '(' << std::endl;
    increaseIndent();
    for (auto param : expression.params()) {
        indent();
        param->accept(*this);
        std::cout << ',' << std::endl;
    }
    decreaseIndent();
    indent();
    std::cout << ')' << std::endl;
}

void naylang::ASTPrintEvaluator::evaluate(naylang::Block &expression) {
    Evaluator::evaluate(expression);
}

void naylang::ASTPrintEvaluator::evaluate(naylang::Lineup &expression) {
    Evaluator::evaluate(expression);
}

void naylang::ASTPrintEvaluator::evaluate(naylang::ObjectConstructor &expression) {
    Evaluator::evaluate(expression);
}

void naylang::ASTPrintEvaluator::evaluate(naylang::ConstantDeclaration &expression) {
    indent();
    std::cout << "def " << expression.name() << " = ";
    expression.value()->accept(*this);
    std::cout << std::endl;
}

void naylang::ASTPrintEvaluator::evaluate(naylang::VariableDeclaration &expression) {
    indent();
    std::cout << "var " << expression.name();
    if (expression.value()) {
        std::cout << " := ";
        expression.value()->accept(*this);
    }
    std::cout << std::endl;
}

void naylang::ASTPrintEvaluator::evaluate(naylang::MethodDeclaration &expression) {
    indent();
    std::cout << "method " << expression.name() << " (";
    for (auto formal : expression.params()) {
        formal->accept(*this);
        std::cout << ", ";
    }
    std::cout << ") ";
    std::cout << "{" << std::endl;

    increaseIndent();
    for (auto line : expression.body()) {
        indent();
        line->accept(*this);
    }
    decreaseIndent();

    indent();
    std::cout << "}" << std::endl;
}

void naylang::ASTPrintEvaluator::evaluate(naylang::IfThen &expression) {
    Evaluator::evaluate(expression);
}

void naylang::ASTPrintEvaluator::evaluate(naylang::IfThenElse &expression) {
    Evaluator::evaluate(expression);
}

void naylang::ASTPrintEvaluator::evaluate(naylang::While &expression) {
    Evaluator::evaluate(expression);
}

void naylang::ASTPrintEvaluator::evaluate(naylang::Return &expression) {
    indent();
    std::cout << "return" << std::endl;
}

void naylang::ASTPrintEvaluator::indent() const {
    std::cout << "|";
    for (int i = 0; i < _indentLevel; i++) {
        std::cout << "-";
    }
}

void naylang::ASTPrintEvaluator::increaseIndent() {
    _indentLevel += 2;
}

void naylang::ASTPrintEvaluator::decreaseIndent() {
    _indentLevel -= 2;
}
