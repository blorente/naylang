//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/evaluators/ExecutionEvaluator.h>
#include <core/model/execution/methods/Method.h>
#include <core/model/execution/methods/NativeMethod.h>
#include <core/model/execution/methods/MethodFactory.h>
#include <core/model/execution/methods/MethodRequest.h>
#include "GraceObject.h"

namespace naylang {

const GraceBoolean & GraceObject::asBoolean() const {
    throw std::string{"Trying to cast a generic GraceObject as GraceBoolean"};
}

const GraceNumber &GraceObject::asNumber() const {
    throw std::string{"Trying to cast a generic GraceObject as GraceNumber"};
}

const GraceString &GraceObject::asString() const {
    throw std::string{"Trying to cast a generic GraceObject as GraceString"};
}

GraceIterable &GraceObject::asIterable() const {
    throw std::string{"Trying to cast a generic GraceObject as GraceIterable"};
}

bool GraceObject::isUndefined() const {
    return true;
}

bool GraceObject::isDone() const {
    return false;
}

void GraceObject::addDefaultMethods() {
    _cell._nativeMethods[":=(_)"] = make_native<Assignment>();
}

GraceObjectPtr GraceObject::dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues) {
    MethodPtr meth = getMethod(methodName);
    MethodRequest req(methodName, paramValues);
    GraceObjectPtr ret = meth->respond(eval, *this, req);
    return ret;
}

void GraceObject::addMethod(const std::string &name, MethodPtr method) {
    _cell._userMethods[name] = method;
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
    return _cell._fields.find(name) != _cell._fields.end();
}

bool GraceObject::hasMethod(const std::string &name) const {
    bool found = false;
    found = found || (_outer != nullptr && _outer->hasMethod(name));
    found = found || _cell._nativeMethods.find(name) != _cell._nativeMethods.end();
    found = found || _cell._userMethods.find(name) != _cell._userMethods.end();
    return found;
}

void GraceObject::setField(const std::string &name, GraceObjectPtr value) {
    _cell._fields[name] = value;
}

MethodPtr GraceObject::getMethod(const std::string &name) {
    if (_cell._userMethods.find(name) != _cell._userMethods.end()) {
        return _cell._userMethods[name];
    }

    if (_cell._nativeMethods.find(name) != _cell._nativeMethods.end()) {
        return _cell._nativeMethods[name];
    }

    if (_outer == nullptr)
        throw std::string{"Method not found"};

    return _outer->getMethod(name);
}

GraceObjectPtr GraceObject::getField(const std::string &name) {
    if (_cell._fields.find(name) == _cell._fields.end()) {
        throw std::string{"Field not found in object"};
    }
    return _cell._fields[name];
}

bool GraceObject::isBlock() const {
    return false;
}

std::string GraceObject::prettyPrint(int indentLevel) {
    std::string res;
    int oldIndent = indentLevel;
    res += "object {\n";
    indentLevel += 2;
    for (auto field : _cell._fields) {
        indent(indentLevel, res);
        res += field.first + " = " + field.second->prettyPrint(indentLevel + 2) + "\n";
    }
    for (auto method : _cell._userMethods) {
        indent(indentLevel, res);
        res += method.second->prettyPrint(method.first, indentLevel) + "\n";
    }
    indentLevel = oldIndent - 2;
    indent(indentLevel, res);
    res += "}";
    return res;
}

void GraceObject::indent(int indentLevel, std::string &res) const {
    for (int i = 0; i < indentLevel; i++) {
        res += " ";
    }
}

const ObjectCell &GraceObject::cell() const {
    return _cell;
}

GraceObjectPtr GraceObject::Assignment::respond(GraceObject &self, MethodRequest &request) {
    self._cell = request.params()[0]->_cell.clone();
    return nullptr;
}
}