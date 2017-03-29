//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "RequestNode.h"

namespace naylang {

RequestNode::RequestNode(const std::string &methodName)  :
        _name{methodName}, _declaration{nullptr} {}

RequestNode::RequestNode(const std::string &methodName, const std::vector<ExpressionPtr> &params) :
        _name{methodName}, _params{params}, _declaration{nullptr} {}

const std::string &RequestNode::identifier() const {
    return _name;
}

const std::vector<ExpressionPtr> &RequestNode::params() const {
    return _params;
}

const MethodDeclaration &RequestNode::declaration() const {
    return *_declaration;
}

void RequestNode::bindTo(MethodDeclaration &binding) {
    _declaration = &binding;
}
}