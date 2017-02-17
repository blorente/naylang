//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "VariableDeclaration.h"

namespace naylang {

VariableDeclaration::VariableDeclaration(const std::string &identifier)
        : _identifier(identifier) {}

void VariableDeclaration::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::string & VariableDeclaration::identifier() const {
        return _identifier;
}

}