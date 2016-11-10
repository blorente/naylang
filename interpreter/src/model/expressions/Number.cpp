#include "Number.h"

namespace naylang {
Number::Number(double value) {
    _value.doubleValue = value;
}

void Number::accept(Visitor &visitor) {
    visitor.process(*this);
}

NumberValue Number::value() const {
    return _value;
}

bool Number::operator==(const Number &other) const {
    return
            (_value.doubleValue == other.value().doubleValue) &&
            (_value.intValue == other.value().intValue) &&
            (_value.byteValue == other.value().byteValue);
}
}