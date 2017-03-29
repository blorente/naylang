//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/evaluators/ExecutionEvaluator.h>
#include "GraceBoolean.h"
#include "GraceString.h"

namespace naylang {

GraceBoolean::GraceBoolean(bool value) : _value{value}{
    addDefaultMethods();
}

const GraceBoolean & GraceBoolean::asBoolean() const {
    return *this;
}

bool GraceBoolean::value() const {
    return _value;
}

GraceObjectPtr GraceBoolean::dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues) {
   return GraceObject::dispatch(methodName, eval, paramValues);
}
void GraceBoolean::addDefaultMethods() {
    _nativeMethods["prefix!"] = make_native<PrefixNot>();
    _nativeMethods["&&(_)"] = make_native<AndAnd>();
    _nativeMethods["||(_)"] = make_native<OrOr>();
    _nativeMethods["not"] = make_native<Not>();
    _nativeMethods["asString"] = make_native<AsString>();
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

GraceObjectPtr GraceBoolean::AndAnd::respond(GraceObject &self, MethodRequest &request) {
    if (self.asBoolean().value() && request.params()[0]->asBoolean().value()) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceBoolean::OrOr::respond(GraceObject &self, MethodRequest &request) {
    if (self.asBoolean()._value || request.params()[0]->asBoolean().value()) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceBoolean::Not::respond(GraceObject &self, MethodRequest &request) {
    if (self.asBoolean().value()) {
        return GraceFalse;
    }
    return GraceTrue;
}

GraceObjectPtr GraceBoolean::AsString::respond(GraceObject &self, MethodRequest &request) {
    if (self.asBoolean().value()) {
        return make_obj<GraceString>("true");
    }
    return make_obj<GraceString>("false");
}
}