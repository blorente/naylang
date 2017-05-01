//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/evaluators/ExecutionEvaluator.h>
#include <core/model/execution/methods/MethodFactory.h>
#include <core/model/execution/methods/MethodRequest.h>
#include "GraceBoolean.h"
#include "GraceString.h"

namespace naylang {

GraceBoolean::GraceBoolean(bool value) {
    _cell._boolVal = value;
    addDefaultMethods();
}

const GraceBoolean & GraceBoolean::asBoolean() const {
    return *this;
}

bool GraceBoolean::value() const {
    return _cell._boolVal;
}

GraceObjectPtr GraceBoolean::dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues) {
   return GraceObject::dispatch(methodName, eval, paramValues);
}
void GraceBoolean::addDefaultMethods() {
    GraceObject::addDefaultMethods();
    _cell._nativeMethods["prefix!"] = make_native<PrefixNot>();
    _cell._nativeMethods["&&(_)"] = make_native<AndAnd>();
    _cell._nativeMethods["||(_)"] = make_native<OrOr>();
    _cell._nativeMethods["not"] = make_native<Not>();
    _cell._nativeMethods["asString"] = make_native<AsString>();
}

bool GraceBoolean::operator==(const GraceObject &rhs) const {
    return rhs.asBoolean().value() == _cell._boolVal;
}

bool GraceBoolean::operator!=(const GraceObject &rhs) const {
    return !(*this == rhs);
}

std::string GraceBoolean::prettyPrint(int indentLevel) {
    MethodRequest req("asString", {});
    auto str = this->_cell._nativeMethods["asString"]->respond(*this, req);
    return str->asString().value();
}

GraceObjectPtr GraceBoolean::createCopy() {
    return make_obj<GraceBoolean>(_cell._boolVal);
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
    if (self.asBoolean().value() || request.params()[0]->asBoolean().value()) {
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
    if (self.cell()._boolVal) {
        return make_obj<GraceString>("true");
    }
    return make_obj<GraceString>("false");
}
}