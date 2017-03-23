//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include <model/execution/objects/GraceDoneDef.h>
#include <model/execution/objects/GraceClosure.h>
#include "Method.h"

namespace naylang {

Method::Method(BlockPtr code) : _params{code->params()}, _code{code->body()} {}

Method::Method(const std::vector<DeclarationPtr> &params, const std::vector<StatementPtr> &body) :
    _params{params}, _code{body} {}

GraceObjectPtr Method::respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) {
    GraceObjectPtr closure = make_obj<GraceClosure>();

    for (int i = 0; i < request.params().size(); i++) {
        closure->setField(params()[i]->name(), request.params()[i]);
    }
    GraceObjectPtr oldScope = context.currentScope();
    context.setScope(closure);
    for (auto node : _code) {
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

const std::vector<StatementPtr> &Method::code() const {
    return _code;
}

const std::vector<DeclarationPtr> &Method::params() const {
    return _params;
}

}