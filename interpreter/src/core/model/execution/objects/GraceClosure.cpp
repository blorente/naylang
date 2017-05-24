//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "GraceClosure.h"
#include "GraceDoneDef.h"

#include <core/model/evaluators/ExecutionEvaluator.h>

namespace naylang {

GraceClosure::GraceClosure(const std::string &name, MethodPtr method, ExecutionEvaluator &context) : GraceObject::GraceObject() {
    addMethod(name, method);
    for (auto param : method->params()) {
        _fields[param->name()] = context.create_obj<GraceDoneDef>();
    }
}

void GraceClosure::addDefaultMethods() {

}

bool GraceClosure::isClosure() const {
    return true;
}
}