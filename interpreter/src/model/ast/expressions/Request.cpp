//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "Request.h"

namespace naylang {

Request::Request(const std::string &methodName) :
        _name{methodName}, _declaration{nullptr} {}

Request::Request(const std::string &methodName, const std::vector<ExpressionPtr> params) :
    _name{methodName}, _params{params}, _declaration{nullptr} {}

void Request::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::string &Request::identifier() const {
    return _name;
}

const std::vector<ExpressionPtr> &Request::params() const {
    return _params;
}

const MethodDeclaration &Request::declaration() const {
    return *_declaration;
}

void Request::bindTo(MethodDeclaration &binding) {
    _declaration = &binding;
}

}