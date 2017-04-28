//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "GraceAST.h"

namespace naylang {
StatementPtr GraceAST::operator[](int index) {
    return _nodes[index];
}

void GraceAST::addNode(StatementPtr node) {
    _nodes.push_back(node);
}

const std::vector<StatementPtr> &GraceAST::nodes() const {
    return _nodes;
}

void GraceAST::addLineLink(StatementPtr node) {
    if (_nodeLinks.count(node->line()) == 0) {
        _nodeLinks[node->line()] = node;
        _lastLine = node->line() > _lastLine ? node->line() : _lastLine;
    }
}
}

