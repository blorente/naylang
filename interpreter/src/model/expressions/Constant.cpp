//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Constant.h"

namespace naylang {

Constant::Constant(const std::string &identifier, std::shared_ptr <Expression> value)
        : _identifier(identifier), _value(value) {}

void Constant::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::string & Constant::identifier() const {
    return _identifier;
}

std::shared_ptr<Expression> Constant::value() const  {
    return _value;
}

}
