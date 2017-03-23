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

const GraceNumber &GraceObject::asNumber() const {
    throw "Trying to cast a generic GraceObject as GraceNumber";
}

bool GraceObject::isUndefined() const {
    return true;
}

bool GraceObject::isDone() const {
    return false;
}

GraceObjectPtr GraceObject::dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues) {
    MethodPtr meth = getMethod(methodName);
    MethodRequest req(methodName, paramValues);
    GraceObjectPtr ret = meth->respond(eval, *this, req);
    return ret;
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

MethodPtr GraceObject::getMethod(const std::string &name) {
    if (_userMethods.find(name) != _userMethods.end()) {
        return _userMethods[name];
    }

    if (_nativeMethods.find(name) != _nativeMethods.end()) {
        return _nativeMethods[name];
    }

    if (_outer == nullptr)
        throw "Method not found";

    return _outer->getMethod(name);
}

GraceObjectPtr GraceObject::getField(const std::string &name) {
    if (_fields.find(name) == _fields.end()) {
        throw "Field not found in object";
    }
    return _fields[name];
}

bool GraceObject::isBlock() const {
    return false;
}
}