//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "GraceClosure.h"
#include "GraceDoneDef.h"

namespace naylang {

GraceClosure::GraceClosure(const std::string &name, MethodPtr method) {
    _methodName = name;
    _methodPtr = method;
    addMethod(name, method);
    for (auto param : method->params()) {
        _cell._fields[param->name()] = make_obj<GraceDoneDef>();
    }
}

void GraceClosure::addDefaultMethods() {
    GraceObject::addDefaultMethods();
}

bool GraceClosure::isClosure() const {
    return true;
}

GraceObjectPtr GraceClosure::createCopy() {
    auto closure = make_obj<GraceClosure>();
    closure->addMethod(_methodName, _methodPtr);
    for (auto param : _methodPtr->params()) {
        closure->_cell._fields[param->name()] = make_obj<GraceDoneDef>();
    }
    return closure;
}
}