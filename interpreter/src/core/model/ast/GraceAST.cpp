//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/evaluators/NextLineFinder.h>
#include "GraceAST.h"

namespace naylang {
StatementPtr GraceAST::operator[](int index) {
    return _nodes[index];
}

StatementPtr GraceAST::getNodeAt(int line) const {
    if (_nodeLinks.count(line) > 0) {
        return _nodeLinks.at(line);
    } else {
        throw "No node found at line " + std::to_string(line);
    }
}

void GraceAST::addNode(StatementPtr node) {
    _nodes.push_back(node);
}

const std::vector<StatementPtr> &GraceAST::nodes() const {
    return _nodes;
}

int GraceAST::lastLine() const {
    return _lastLine;
}

void GraceAST::addLineLink(StatementPtr node) {
    if (_nodeLinks.count(node->line()) == 0) {
        _nodeLinks[node->line()] = node;
        _lastLine = node->line() > _lastLine ? node->line() : _lastLine;
    }
}

int GraceAST::getNextLine(int curLine, bool stepIn) {
    auto curNode = _nodeLinks[curLine];
    NextLineFinder eval;
    return eval.getNextLine(curNode.get(), stepIn);
}
}

