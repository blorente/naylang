//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "NumberLiteral.h"

namespace naylang {

NumberLiteral::NumberLiteral(double value) : _value(value) {}

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