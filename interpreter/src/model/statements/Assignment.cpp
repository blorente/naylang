//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Assignment.h"
#include <model/statements/VariableDeclaration.h>

namespace naylang {

Assignment::Assignment(std::shared_ptr<VariableDeclaration> declaration, std::shared_ptr <Expression> value)
        : _declaration(declaration), _value(value) {}

void Assignment::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::string & Assignment::identifier() const {
    return _declaration->identifier();
}

ExpressionPtr Assignment::value() const {
    return _value;
}

}