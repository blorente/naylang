//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "MethodRequest.h"

namespace naylang {

MethodRequest::MethodRequest(const std::string &name) : _name{name} {}

MethodRequest::MethodRequest(const std::string &name, std::vector<GraceObjectPtr> params) : _name{name}, _params{params}{}

const std::string &MethodRequest::name() const {
    return _name;
}

const std::vector<GraceObjectPtr> &MethodRequest::params() const {
    return _params;
}
}