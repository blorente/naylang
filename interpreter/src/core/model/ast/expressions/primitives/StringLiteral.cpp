//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "StringLiteral.h"

namespace naylang {

StringLiteral::StringLiteral(const std::string &value, int line, int col) :
        _value{value}, Expression(line, col) {}

StringLiteral::StringLiteral(const std::string &value) :
        StringLiteral(value, -1, -1) {}

void StringLiteral::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::string &StringLiteral::value() const {
    return _value;
}

bool StringLiteral::operator==(const StringLiteral &rhs) const {
    return _value == rhs._value;
}

bool StringLiteral::operator!=(const StringLiteral &rhs) const {
    return !(rhs == *this);
}
}