//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "GraceObject.h"

namespace naylang {
GraceObject::GraceObject() : _defined{false} {}

GraceObject::GraceObject(double number) : _number{number}, _isNumber{true}, _defined{true} {}

bool GraceObject::isUndefined() const {
    return !_defined;
}

double GraceObject::asNumber() const {
    if (!_isNumber) {
        throw "NaN";
    }

    return _number;
}

bool GraceObject::operator==(const GraceObject &other) const {
    if (_isNumber && other._isNumber)
        return _number == other._number;

    if (!_defined && !other._defined)
        return true;

    return false;
}

bool GraceObject::operator!=(const GraceObject &other) const {
    return !(other == *this);
}
}