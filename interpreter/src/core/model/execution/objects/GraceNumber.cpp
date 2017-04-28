//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/execution/methods/MethodFactory.h>
#include <core/model/execution/methods/MethodRequest.h>

#include "GraceNumber.h"
#include "GraceBoolean.h"
#include "GraceString.h"

namespace naylang {

GraceNumber::GraceNumber(double value) {
    _cell._numVal = value;
    addDefaultMethods();
}

void GraceNumber::addDefaultMethods() {
    _cell._nativeMethods["prefix!"] = make_native<Negative>();
    _cell._nativeMethods["==(_)"] = make_native<Equals>();
    _cell._nativeMethods["!=(_)"] = make_native<NotEquals>();
    _cell._nativeMethods["+(_)"] = make_native<Add>();
    _cell._nativeMethods["-(_)"] = make_native<Sub>();
    _cell._nativeMethods["*(_)"] = make_native<Mul>();
    _cell._nativeMethods["/(_)"] = make_native<Div>();
    _cell._nativeMethods["%(_)"] = make_native<Mod>();
    _cell._nativeMethods["^(_)"] = make_native<Pow>();
    _cell._nativeMethods["asString(_)"] = make_native<AsString>();
}

const GraceNumber &GraceNumber::asNumber() const {
    return *this;
}

double GraceNumber::value() const {
    return _cell._numVal;
}

std::string GraceNumber::prettyPrint(int indentLevel) {
    return std::to_string(_cell._numVal);
}

GraceObjectPtr GraceNumber::Equals::respond(GraceObject &self, MethodRequest &request) {
    if (self.asNumber().value() == request.params()[0]->asNumber().value()) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceNumber::NotEquals::respond(GraceObject &self, MethodRequest &request) {
    if (self.asNumber().value() != request.params()[0]->asNumber().value()) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceNumber::Negative::respond(GraceObject &self, MethodRequest &request) {
    double value = -self.asNumber().value();
    return make_obj<GraceNumber>(value);
}

GraceObjectPtr GraceNumber::Add::respond(GraceObject &self, MethodRequest &request) {
    double value = self.asNumber().value() + request.params()[0]->asNumber().value();
    return make_obj<GraceNumber>(value);
}

GraceObjectPtr GraceNumber::Sub::respond(GraceObject &self, MethodRequest &request) {
    double value = self.asNumber().value() - request.params()[0]->asNumber().value();
    return make_obj<GraceNumber>(value);
}

GraceObjectPtr GraceNumber::Mul::respond(GraceObject &self, MethodRequest &request) {
    double value = self.asNumber().value() * request.params()[0]->asNumber().value();
    return make_obj<GraceNumber>(value);
}

GraceObjectPtr GraceNumber::Div::respond(GraceObject &self, MethodRequest &request) {
    double value = self.asNumber().value() / request.params()[0]->asNumber().value();
    return make_obj<GraceNumber>(value);
}

GraceObjectPtr GraceNumber::Mod::respond(GraceObject &self, MethodRequest &request) {
    double value = (int) self.asNumber().value() % (int) request.params()[0]->asNumber().value();
    return make_obj<GraceNumber>(value);
}

GraceObjectPtr GraceNumber::Pow::respond(GraceObject &self, MethodRequest &request) {
    double value = self.asNumber().value();
    double base = self.asNumber().value();
    int power = (int) request.params()[0]->asNumber().value();
    for (int i = 1; i < power; i++) {
        value *= base;
    }
    return make_obj<GraceNumber>(value);
}

GraceObjectPtr GraceNumber::Greater::respond(GraceObject &self, MethodRequest &request) {
    if (self.asNumber().value() > request.params()[0]->asNumber().value()) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceNumber::GreaterEq::respond(GraceObject &self, MethodRequest &request) {
    if (self.asNumber().value() >= request.params()[0]->asNumber().value()) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceNumber::Less::respond(GraceObject &self, MethodRequest &request) {
    if (self.asNumber().value() < request.params()[0]->asNumber().value()) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceNumber::LessEq::respond(GraceObject &self, MethodRequest &request) {
    if (self.asNumber().value() <= request.params()[0]->asNumber().value()) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceNumber::AsString::respond(GraceObject &self, MethodRequest &request) {
    std::string value = std::to_string(self.asNumber().value());
    return make_obj<GraceString>(value);
}
}