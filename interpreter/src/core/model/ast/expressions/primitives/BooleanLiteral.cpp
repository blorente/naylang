//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "BooleanLiteral.h"

namespace naylang {
BooleanLiteral::BooleanLiteral(bool value) : BooleanLiteral(value, -1, -1) {}

BooleanLiteral::BooleanLiteral(bool value, int line, int col) :
        _value(value), Expression(line, col) {}

void BooleanLiteral::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

bool BooleanLiteral::operator==(const BooleanLiteral &other) {
    return other._value == _value;
}

bool BooleanLiteral::value() const {
    return _value;
}


}