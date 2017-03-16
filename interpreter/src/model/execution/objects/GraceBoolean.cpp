//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "GraceBoolean.h"
#include "GraceObjectFactory.h"

namespace naylang {

GraceBoolean::GraceBoolean(bool value) : _value{value} {

        _methodTable["prefix!"] = make_meth(make_node<Block>());
}

const GraceBoolean & GraceBoolean::asBoolean() const {
    return *this;
}

bool GraceBoolean::value() const {
    return _value;
}

void GraceBoolean::dispatch(const std::string &methodName, Evaluator &eval) {
    eval.evaluate(*_methodTable[methodName]->code());
}
}