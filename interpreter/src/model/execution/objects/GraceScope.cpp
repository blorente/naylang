//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "GraceScope.h"

namespace naylang {
void GraceScope::addDefaultMethods() {
    // Do nothing
}

GraceObjectPtr GraceScope::dispatch(const std::string &methodName, ExecutionEvaluator &eval,
                                       const std::vector<GraceObjectPtr> &paramValues) {
    return GraceObject::dispatch(methodName, eval, paramValues);
}

bool GraceScope::isScope() const {
    return true;
}
}