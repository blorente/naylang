//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_NATIVEMETHOD_H
#define NAYLANG_NATIVEMETHOD_H

#include <core/model/execution/objects/GraceObject.h>
#include <core/model/evaluators/Evaluator.h>
#include "Method.h"

namespace naylang {

class NativeMethod : public Method {

public:

    virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request) = 0;
    virtual GraceObjectPtr respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) {
        return respond(self, request);
    }
};
} // end namespace naylang

#endif //NAYLANG_NATIVEMETHOD_H
