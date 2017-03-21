//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include <model/evaluators/ExecutionEvaluator.h>
#include "GraceObject.h"

namespace naylang {

GraceObject::GraceObject() : _outer{nullptr} {}

const GraceBoolean & GraceObject::asBoolean() const {
    throw "Trying to cast a generic GraceObject as GraceBoolean";
}

bool GraceObject::isUndefined() const {
    return true;
}

bool GraceObject::isDone() const {
    return false;
}

GraceObjectPtr GraceObject::dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues) {
    MethodPtr meth = nullptr;
    if (_userMethods.find(methodName) != _userMethods.end()) {
        meth = _userMethods[methodName];
    } else {
        if (_nativeMethods.find(methodName) != _nativeMethods.end()) {
            meth = _nativeMethods[methodName];
        } else {
            throw "Method not found in native methods";
        }
    }
    MethodRequest req(methodName, paramValues);
    return meth->respond(eval, *this, req);
}

void GraceObject::addMethod(const std::string &name, MethodPtr method) {
    _userMethods[name] = method;
}

bool GraceObject::isScope() const {
    return false;
}

GraceObjectPtr GraceObject::outer() {
    return _outer;
}

void GraceObject::setOuter(GraceObjectPtr outer) {
    _outer = outer;
}

bool GraceObject::isClosure() const {
    return false;
}

bool GraceObject::hasField(const std::string &name) const {
    return _fields.find(name) != _fields.end();
}

bool GraceObject::hasMethod(const std::string &name) const {
    bool found = false;
    found = found || (_outer != nullptr && _outer->hasMethod(name));
    found = found || _nativeMethods.find(name) != _nativeMethods.end();
    found = found || _userMethods.find(name) != _userMethods.end();
    return found;
}

void GraceObject::setField(const std::string &name, GraceObjectPtr value) {
    _fields[name] = value;
}

bool GraceDoneDef::isDone() const {
    return true;
}

void GraceDoneDef::addDefaultMethods() {
    // Some methods
}

GraceObjectPtr GraceDoneDef::dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues) {
    return GraceObject::dispatch(methodName, eval, paramValues);
}

bool GraceDoneDef::operator==(const GraceObject &rhs) const {
    return rhs.isDone();
}

bool GraceDoneDef::operator!=(const GraceObject &rhs) const {
    return !(*this == rhs);
}

void GraceScope::addDefaultMethods() {
    // Do nothing
}

GraceObjectPtr GraceScope::dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues) {
    return GraceObject::dispatch(methodName, eval, paramValues);
}

bool GraceScope::isScope() const {
    return true;
}
}