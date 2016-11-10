#include "Number.h"

namespace naylang {

bool NumberValue::operator==(const NumberValue &other) const {
    return
            (doubleValue == other.doubleValue) &&
            (intValue == other.intValue) &&
            (byteValue == other.byteValue);
}

Number::Number(double value) {
    _value.doubleValue = value;
}

NumberValue Number::value() const {
    return _value;
}

bool Number::operator==(const Number &other) const {
    return _value == other.value();
}
}
