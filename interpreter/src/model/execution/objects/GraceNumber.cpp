//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "GraceNumber.h"
#include "GraceBoolean.h"

namespace naylang {

GraceNumber::GraceNumber(double value) : _value{value} {}

void GraceNumber::addDefaultMethods() {
    _nativeMethods["==(_)"] = make_native<Equals>();
    _nativeMethods["!=(_)"] = make_native<NotEquals>();
    _nativeMethods["+(_)"] = make_native<Add>();
    _nativeMethods["-(_)"] = make_native<Sub>();
    _nativeMethods["*(_)"] = make_native<Mul>();
    _nativeMethods["/(_)"] = make_native<Div>();
    _nativeMethods["%(_)"] = make_native<Mod>();
    _nativeMethods["^(_)"] = make_native<Pow>();
}

const GraceNumber &GraceNumber::asNumber() const {
    return *this;
}

double GraceNumber::value() const {
    return _value;
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

}