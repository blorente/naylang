//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "CharLiteral.h"

namespace naylang {

CharLiteral::CharLiteral(char value) : CharLiteral(value, -1, -1) {}

CharLiteral::CharLiteral(char value, int line, int col) :
        _value(value), Expression(line, col) {}

void CharLiteral::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

bool CharLiteral::operator==(const CharLiteral &other) {
    return _value == other._value;
}

char CharLiteral::value() const {
    return _value;
}

}
