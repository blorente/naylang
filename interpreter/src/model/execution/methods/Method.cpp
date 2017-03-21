//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include <model/execution/objects/GraceDoneDef.h>
#include "Method.h"

namespace naylang {

Method::Method(BlockPtr code) : _code{code} {}

const BlockPtr &Method::code() const {
    return _code;
}

GraceObjectPtr Method::respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) {
    _code->accept(context);
    GraceObjectPtr closure = context.partial();

    for (int i = 0; i < request.params().size(); i++) {
        closure->setField(params()[i]->name(), request.params()[i]);
    }
    GraceObjectPtr oldScope = context.currentScope();
    context.setScope(closure);
    for (auto node : _code->body()) {
        node->accept(context);
    }
    GraceObjectPtr ret = context.partial();
    if (ret == closure) {
        // The return value hasen't changed. Return Done
        ret = make_obj<GraceDoneDef>();
    }
    context.setScope(oldScope);
    return ret;
}

const std::vector<DeclarationPtr> &Method::params() const {
    return _code->params();
}

}