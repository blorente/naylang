//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "NumberLiteral.h"

namespace naylang {

NumberLiteral::NumberLiteral(double value, int line, int col) :
        _value(value), Expression(line, col) {}

NumberLiteral::NumberLiteral(double value) :
        NumberLiteral(value, -1, -1) {}

void NumberLiteral::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

bool NumberLiteral::operator==(const NumberLiteral &other) {
    return static_cast<NumberLiteral>(other)._value == _value;
}

double NumberLiteral::value() const {
    return _value;
}

}