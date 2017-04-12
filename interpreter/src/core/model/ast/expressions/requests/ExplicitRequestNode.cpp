//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "ExplicitRequestNode.h"

namespace naylang {

ExplicitRequestNode::ExplicitRequestNode(const std::string &method, ExpressionPtr receiver) :
        _receiver{receiver}, RequestNode::RequestNode(method) {}

ExplicitRequestNode::ExplicitRequestNode(const std::string &method, ExpressionPtr receiver, int line, int col) :
        _receiver{receiver}, RequestNode::RequestNode(method, line, col) {}

ExplicitRequestNode::ExplicitRequestNode(const std::string &method, ExpressionPtr receiver,
                                         const std::vector<ExpressionPtr> &params) :
        _receiver{receiver}, RequestNode::RequestNode(method, params) {}

ExplicitRequestNode::ExplicitRequestNode(const std::string &method, ExpressionPtr receiver,
                                         const std::vector<ExpressionPtr> &params, int line, int col) :
        _receiver{receiver}, ExplicitRequestNode::RequestNode(method, params, line, col) {}

const ExpressionPtr &ExplicitRequestNode::receiver() const {
    return _receiver;
}

void ExplicitRequestNode::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}
}