//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "ConstantDeclaration.h"

namespace naylang {

ConstantDeclaration::ConstantDeclaration(const std::string &name, ExpressionPtr value) :
        _name(name), _value(value) {}

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