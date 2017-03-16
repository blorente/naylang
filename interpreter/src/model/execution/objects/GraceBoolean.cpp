//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "GraceBoolean.h"
#include "GraceObjectFactory.h"

namespace naylang {

GraceBoolean::GraceBoolean(bool value) : _value{value} {

        _methodTable["prefix!"] = make_meth(make_node<Block>());
}

const GraceBoolean & GraceBoolean::asBoolean() const {
    return *this;
}

bool GraceBoolean::value() const {
    return _value;
}

void GraceBoolean::dispatch(const std::string &methodName, Evaluator &eval) {
    eval.evaluate(*_methodTable[methodName]->code());
}

bool GraceBoolean::operator==(const GraceObject &rhs) const {
    return rhs.asBoolean()._value == _value;
}

bool GraceBoolean::operator!=(const GraceObject &rhs) const {
    return !(*this == rhs);
}

GraceObjectPtr GraceBoolean::PrefixNot::respond(GraceObject &self, MethodRequest &request) {
    if (self.asBoolean().value()) {
        return GraceFalse;
    }
    return GraceTrue;
}
}