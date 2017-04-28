//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "BindingEvaluator.h"

namespace naylang {

const std::map<std::string, Declaration *> &BindingEvaluator::symbolTable() const {
    return _symbolTable;
}

void BindingEvaluator::evaluate(ImplicitRequestNode &expression) {
    if (_symbolTable.find(expression.identifier()) == _symbolTable.end()) {
        throw std::string{"Binding not found in symbol table"};
    }
    expression.bindTo(static_cast<MethodDeclaration &>(*_symbolTable[expression.identifier()]));
}

void BindingEvaluator::evaluate(ConstantDeclaration &expression) {
    if(_symbolTable.find(expression.name()) != _symbolTable.end()) {
        throw std::string{"Binding exists in symbol table"};
    }
    _symbolTable[expression.name()] = &expression;
}

void BindingEvaluator::evaluate(VariableDeclaration &expression) {
    if(_symbolTable.find(expression.name()) != _symbolTable.end()) {
        throw std::string{"Binding exists in symbol table"};
    }
    _symbolTable[expression.name()] = &expression;
}

void BindingEvaluator::evaluate(MethodDeclaration &expression) {
    if(_symbolTable.find(expression.name()) != _symbolTable.end()) {
        throw std::string{"Binding exists in symbol table"};
    }
    _symbolTable[expression.name()] = &expression;
}

void BindingEvaluator::evaluate(ExplicitRequestNode &expression) {
    if (_symbolTable.find(expression.identifier()) == _symbolTable.end()) {
        throw std::string{"Binding not found in symbol table"};
    }
    expression.bindTo(static_cast<MethodDeclaration &>(*_symbolTable[expression.identifier()]));
}

}