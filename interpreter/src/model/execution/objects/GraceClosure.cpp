//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "GraceClosure.h"
#include "GraceDoneDef.h"

namespace naylang {

GraceClosure::GraceClosure(const std::string &name, MethodPtr method) : GraceObject::GraceObject() {
    addMethod(name, method);
    for (auto param : method->code()->params()) {
        _fields[param->name()] = make_obj<GraceDoneDef>();
    }
}

void GraceClosure::addDefaultMethods() {

}

bool GraceClosure::isClosure() const {
    return true;
}
}