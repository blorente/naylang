//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include <model/evaluators/ExecutionEvaluator.h>
#include "GraceObject.h"

namespace naylang {

const GraceBoolean & GraceObject::asBoolean() const {
    throw "Trying to cast a generic GraceObject as GraceBoolean";
}

bool GraceObject::isUndefined() const {
    return true;
}

bool GraceObject::isDone() const {
    return false;
}

GraceObjectPtr GraceObject::dispatch(const std::string &methodName, ExecutionEvaluator &eval) {
    if (_nativeMethods.find(methodName) == _nativeMethods.end())
        throw "Method not found";

    MethodPtr meth = _nativeMethods[methodName];
    std::vector<GraceObjectPtr> params;
    for (int i = 0; i < meth->numParams(); i++) {
        params.push_back(std::move(eval.objectStack().top()));
    }
    MethodRequest req(methodName, params);

    return meth->respond(eval, *this, req);
}

bool GraceDone::isDone() const {
    return true;
}

void GraceDone::addDefaultMethods() {
    // Some methods
}

GraceObjectPtr GraceDone::dispatch(const std::string &methodName, ExecutionEvaluator &eval) {
    return GraceObject::dispatch(methodName, eval);
}
}