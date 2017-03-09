//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "BindingEvaluator.h"

namespace naylang {

void BindingEvaluator::evaluate(VariableReference &expression) {
    Evaluator::evaluate(expression);
}

void BindingEvaluator::evaluate(Request &expression) {
    Evaluator::evaluate(expression);
}

const std::map<std::string, DeclarationPtr> &BindingEvaluator::symbolTable() const {
    return _symbolTable;
}

void BindingEvaluator::evaluate(ConstantDeclaration &expression) {
    Evaluator::evaluate(expression);
}

void BindingEvaluator::evaluate(VariableDeclaration &expression) {
    Evaluator::evaluate(expression);
}

void BindingEvaluator::evaluate(MethodDeclaration &expression) {
    Evaluator::evaluate(expression);
}

}