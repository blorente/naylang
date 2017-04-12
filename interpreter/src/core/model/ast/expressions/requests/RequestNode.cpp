//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "RequestNode.h"

namespace naylang {

RequestNode::RequestNode(const std::string &methodName, const std::vector<ExpressionPtr> &params, int line, int col) :
        _name{methodName}, _params{params}, _declaration{nullptr},
        Expression(line, col) {}

RequestNode::RequestNode(const std::string &methodName, const std::vector<ExpressionPtr> &params) :
        RequestNode(methodName, params, -1, -1) {}

RequestNode::RequestNode(const std::string &methodName)  :
        RequestNode(methodName, {}) {}

RequestNode::RequestNode(const std::string &methodName, int line, int col) :
        RequestNode::RequestNode(methodName, {}, line, col) {}

const std::string &RequestNode::identifier() const {
    return _name;
}

const std::vector<ExpressionPtr> &RequestNode::params() const {
    return _params;
}

Declaration *RequestNode::declaration() const {
    return _declaration;
}

void RequestNode::bindTo(MethodDeclaration &binding) {
    _declaration = &binding;
}

void RequestNode::bindTo(VariableDeclaration &binding) {
    _declaration = &binding;
}

void RequestNode::bindTo(ConstantDeclaration &binding) {
    _declaration = &binding;
}
}