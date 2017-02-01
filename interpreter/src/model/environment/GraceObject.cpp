//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "GraceObject.h"

namespace naylang {
GraceObject::GraceObject() : _kind{GraceObjectKind::UNDEFINED} {}

GraceObject::GraceObject(double number) : _kind{GraceObjectKind::NUMBER}, _number{number} {}

GraceObject::GraceObject(ExpressionPtr body) : _kind{GraceObjectKind::METHOD} {
    _body = std::move(body);
}

bool GraceObject::isUndefined() const {
    return _kind == GraceObjectKind::UNDEFINED;
}

double GraceObject::asNumber() const {
    if (_kind != GraceObjectKind::NUMBER)
        throw "NaN";

    return _number;
}

ExpressionPtr GraceObject::asMethod() const {
    if(_kind != GraceObjectKind::METHOD)
        throw "Not a Method";

    return _body;
}

bool GraceObject::operator==(const GraceObject &other) const {
    if (_kind == GraceObjectKind::UNDEFINED &&
            other._kind == GraceObjectKind::UNDEFINED)
        return true;

    if (_kind == GraceObjectKind::NUMBER &&
            other._kind == GraceObjectKind::NUMBER)
        return _number == other._number;

    if (_kind == GraceObjectKind::METHOD &&
            other._kind == GraceObjectKind::METHOD)
        return _body == other._body;

    return false;
}

bool GraceObject::operator!=(const GraceObject &other) const {
    return !(other == *this);
}

/*
const std::map<Identifier, GraceObject> & GraceObject::getSelf() const {
    return _self;
}

void GraceObject::addField(const Identifier &name, const GraceObject &value) {
    _self[name] = value;
}
 */
}