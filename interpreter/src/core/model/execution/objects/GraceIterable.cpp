//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "GraceIterable.h"
#include "GraceDoneDef.h"
#include "GraceBlock.h"

namespace naylang {

void GraceIterable::addDefaultMethods() {
    // Some methods
}

GraceIterable::GraceIterable(const std::vector<GraceObjectPtr> &contents) : _contents{contents} {}

const std::vector<GraceObjectPtr> &GraceIterable::values() const {
    return _contents;
}

GraceIterable &GraceIterable::asIterable() const {
    return (GraceIterable &)(*this);
}

void GraceIterable::setElem(int index, GraceObjectPtr value) {
    _contents[index] = value;
}

GraceObjectPtr GraceIterable::Append::respond(GraceObject &self, MethodRequest &request) {
    static_cast<GraceIterable &>(self)._contents.push_back(request.params()[0]);
    return make_obj<GraceDoneDef>();
}

GraceObjectPtr GraceIterable::Do::respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) {
    auto block = static_cast<GraceBlock &>(*request.params()[0]);
    auto lineup = self.asIterable();
    for (int i = 0; i < lineup._contents.size(); i++) {
        self.asIterable().setElem(i, block.dispatch("apply", context, {lineup._contents[i]}));
    }
    return make_obj<GraceDoneDef>();
}

GraceObjectPtr GraceIterable::Do::respond(GraceObject &self, MethodRequest &request) {
    ExecutionEvaluator eval;
    return respond(eval, self, request);
}
}