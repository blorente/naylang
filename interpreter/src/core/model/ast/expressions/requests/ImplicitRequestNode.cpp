//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "ImplicitRequestNode.h"

namespace naylang {

ImplicitRequestNode::ImplicitRequestNode(const std::string &methodName) :
    RequestNode::RequestNode(methodName) {}

ImplicitRequestNode::ImplicitRequestNode(const std::string &methodName, const std::vector<ExpressionPtr> &params) :
        RequestNode::RequestNode(methodName, params) {}

void ImplicitRequestNode::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}
}