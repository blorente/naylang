//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "Method.h"

namespace naylang {

Method::Method(BlockPtr code) : _code{code} {}

const BlockPtr &Method::code() const {
    return _code;
}

GraceObjectPtr Method::respond(Evaluator &context, GraceObject &self, MethodRequest &request) {
    return GraceDone;
}

int Method::numParams() {
    throw "Default params num not implemented";
}

}