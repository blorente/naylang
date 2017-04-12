//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "ConstantDeclaration.h"

namespace naylang {

ConstantDeclaration::ConstantDeclaration(const std::string &identifier, ExpressionPtr value, int line, int col) :
        _name{identifier}, _value(value), Declaration::Declaration(line, col) {}

ConstantDeclaration::ConstantDeclaration(const std::string &name, ExpressionPtr value) :
        ConstantDeclaration(name, value, -1, -1){}

void ConstantDeclaration::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::string & ConstantDeclaration::name() const {
    return _name;
}

ExpressionPtr ConstantDeclaration::value() const {
    return _value;
}

}