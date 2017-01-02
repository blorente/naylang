//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "GraceObject.h"

namespace naylang {
bool GraceObject::isDefined() {
    return !_undefined;
}

void GraceObject::addField(double number) {
    _undefined = false;
    _number = number;
}

void GraceObject::addField(ExpressionPtr expression) {
    _undefined = false;
    _expression = expression;
}

double GraceObject::value() const {
    return _number;
}

bool GraceObject::operator!=(const GraceObject &other) const {
    return !(other == *this);
}

bool GraceObject::operator==(const GraceObject &other) const {
    return (_undefined && other._undefined) ||
            ((_number == other._number) && (_expression == other._expression));
}
}