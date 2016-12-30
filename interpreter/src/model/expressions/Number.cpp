//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Number.h"

namespace naylang {

Number::Number(double value) : _value(value) {}

void Number::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

bool Number::operator==(const Number &other) {
    return static_cast<Number>(other)._value == _value;
}

double Number::value() const {
    return _value;
}

}