//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "ImplicitRequestNode.h"

namespace naylang {

ImplicitRequestNode::ImplicitRequestNode(const std::string &methodName) :
        RequestNode::RequestNode(methodName) {}

ImplicitRequestNode::ImplicitRequestNode(const std::string &methodName, int line, int col) :
        RequestNode(methodName, line, col) {}

ImplicitRequestNode::ImplicitRequestNode(const std::string &methodName, const std::vector<ExpressionPtr> &params) :
        RequestNode(methodName, params) {}

ImplicitRequestNode::ImplicitRequestNode(const std::string &methodName, const std::vector<ExpressionPtr> &params,
                                         int line, int col) :
        RequestNode(methodName, params, line, col) {}

void ImplicitRequestNode::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}
}