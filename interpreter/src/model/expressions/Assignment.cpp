//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Assignment.h"

namespace naylang {

Assignment::Assignment(const std::string &identifier, std::shared_ptr <Expression> value)
        : _identifier(identifier), _value(value) {}

void Assignment::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::string & Assignment::identifier() const {
    return _identifier;
}

std::shared_ptr<Expression> Assignment::value() const {
    return _value;
}

}