//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "GraceClosure.h"

namespace naylang {

GraceClosure::GraceClosure(MethodPtr method) : GraceObject::GraceObject() {
    addMethod("apply", method);
}

GraceObjectPtr GraceClosure::dispatch(const std::string &methodName, ExecutionEvaluator &eval,
                                      const std::vector<GraceObjectPtr> &paramValues) {
    return GraceObject::dispatch(methodName, eval, paramValues);
}

void GraceClosure::addDefaultMethods() {

}

bool GraceClosure::isClosure() const {
    return true;
}
}