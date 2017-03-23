//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "GraceString.h"
#include "GraceBoolean.h"

namespace naylang {

GraceString::GraceString(const std::string &value) : _value(value) {}

const std::string &GraceString::value() const {
    return _value;
}

void GraceString::addDefaultMethods() {

}

const GraceString &GraceString::asString() const {
    return *this;
}

GraceObjectPtr GraceString::Equals::respond(GraceObject &self, MethodRequest &request) {
    if (self.asString().value() == request.params()[0]->asString().value()) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceString::NotEquals::respond(GraceObject &self, MethodRequest &request) {
    if (self.asString().value() != request.params()[0]->asString().value()) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceString::Greater::respond(GraceObject &self, MethodRequest &request) {
    if (self.asString().value().compare(request.params()[0]->asString().value()) > 0) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceString::GreaterEq::respond(GraceObject &self, MethodRequest &request) {
    if (self.asString().value().compare(request.params()[0]->asString().value()) >= 0) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceString::Less::respond(GraceObject &self, MethodRequest &request) {
    if (self.asString().value().compare(request.params()[0]->asString().value()) < 0) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceString::LessEq::respond(GraceObject &self, MethodRequest &request) {
    if (self.asString().value().compare(request.params()[0]->asString().value()) <= 0) {
        return GraceTrue;
    }
    return GraceFalse;
}
}