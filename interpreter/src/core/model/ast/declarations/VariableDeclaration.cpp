//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "VariableDeclaration.h"

namespace naylang {

VariableDeclaration::VariableDeclaration(const std::string &identifier, ExpressionPtr initialValue, int line, int col) :
        _identifier{identifier}, _initialValue{initialValue},
        VariableDeclaration::Declaration(line, col) {}

VariableDeclaration::VariableDeclaration(const std::string &identifier, int line, int col) :
        VariableDeclaration(identifier, nullptr, line, col) {}

VariableDeclaration::VariableDeclaration(const std::string &identifier, ExpressionPtr initialValue) :
        VariableDeclaration(identifier, initialValue, -1, -1) {}

VariableDeclaration::VariableDeclaration(const std::string &identifier) :
        VariableDeclaration(identifier, -1, -1) {}

void VariableDeclaration::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::string & VariableDeclaration::name() const {
    return _identifier;
}

const ExpressionPtr &VariableDeclaration::value() const {
    return _initialValue;
}

}