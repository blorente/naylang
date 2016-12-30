//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Boolean.h"

namespace naylang {
Boolean::Boolean(bool value) : _value(value) {}

void Boolean::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

bool Boolean::operator==(const Boolean &other) {
    return other._value == _value;
}

bool Boolean::value() {
    return _value;
}


}