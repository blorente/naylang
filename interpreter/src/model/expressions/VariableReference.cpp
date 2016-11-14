//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "VariableReference.h"

namespace naylang {

VariableReference::VariableReference(const std::string &identifier)
        : _identifier(identifier) {}

void VariableReference::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::string& VariableReference::identifier() const {
    return _identifier;
}

}