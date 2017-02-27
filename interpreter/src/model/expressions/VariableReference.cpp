//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "VariableReference.h"
#include <model/statements/VariableDeclaration.h>

namespace naylang {

VariableReference::VariableReference(std::shared_ptr<VariableDeclaration> declaration)
        : _declaration(declaration) {}

void VariableReference::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::string& VariableReference::identifier() const {
    return _declaration->identifier();
}

VariableReference::VariableReference(const std::string &constIdentifier) {
    // Create a phantom declaration, which should be deleted once the constants are dealt with
    _declaration = std::make_shared<VariableDeclaration>(constIdentifier);
}

}