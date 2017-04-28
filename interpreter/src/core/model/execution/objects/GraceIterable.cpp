//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/evaluators/ExecutionEvaluator.h>
#include <core/model/execution/methods/MethodRequest.h>
#include "GraceIterable.h"
#include "GraceDoneDef.h"
#include "GraceBlock.h"

namespace naylang {

GraceIterable::GraceIterable(const std::vector<GraceObjectPtr> &contents) {
    _cell._vectorVal = contents;
}

void GraceIterable::addDefaultMethods() {
    // Some methods
}

const std::vector<GraceObjectPtr> &GraceIterable::values() const {
    return _cell._vectorVal;
}

GraceIterable &GraceIterable::asIterable() const {
    return (GraceIterable &)(*this);
}

void GraceIterable::setElem(int index, GraceObjectPtr value) {
    _cell._vectorVal[index] = value;
}

GraceObjectPtr GraceIterable::Append::respond(GraceObject &self, MethodRequest &request) {
    static_cast<GraceIterable &>(self)._cell._vectorVal.push_back(request.params()[0]);
    return make_obj<GraceDoneDef>();
}

GraceObjectPtr GraceIterable::Do::respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) {
    auto block = static_cast<GraceBlock &>(*request.params()[0]);
    auto lineup = self.asIterable();
    for (int i = 0; i < lineup._cell._vectorVal.size(); i++) {
        self.asIterable().setElem(i, block.dispatch("apply", context, {lineup._cell._vectorVal[i]}));
    }
    return make_obj<GraceDoneDef>();
}

GraceObjectPtr GraceIterable::Do::respond(GraceObject &self, MethodRequest &request) {
    ExecutionEvaluator eval;
    return respond(eval, self, request);
}
}