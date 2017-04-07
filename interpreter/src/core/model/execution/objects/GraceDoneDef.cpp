//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "GraceDoneDef.h"

namespace naylang {

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
}