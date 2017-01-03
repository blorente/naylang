//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "GraceObject.h"

namespace naylang {
GraceObject::GraceObject() : _defined{false} {}

GraceObject::GraceObject(double number) : _number{number}, _isNumber{true}, _defined{true} {}

GraceObject::GraceObject(ExpressionPtr body) : _isMethod{true}, _defined{true} {
    _body = std::move(body);
}

bool GraceObject::isUndefined() const {
    return !_defined;
}

double GraceObject::asNumber() const {
    if (!_isNumber)
        throw "NaN";

    return _number;
}

ExpressionPtr GraceObject::asMethod() const {
    if(!_isMethod)
        throw "Not a Method";

    return _body;
}

bool GraceObject::operator==(const GraceObject &other) const {
    if (!_defined && !other._defined)
        return true;

    if (_isNumber && other._isNumber)
        return _number == other._number;

    if (_isMethod && other._isMethod)
        return _body == other._body;

    return false;
}

bool GraceObject::operator!=(const GraceObject &other) const {
    return !(other == *this);
}
}