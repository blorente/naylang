//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "VariableDeclaration.h"

namespace naylang {

VariableDeclaration::VariableDeclaration(const std::string &identifier)
        : _identifier(identifier) {}

VariableDeclaration::VariableDeclaration(const std::string &identifier, ExpressionPtr intialValue) :
        _identifier{identifier}, _initialValue{intialValue} {}

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