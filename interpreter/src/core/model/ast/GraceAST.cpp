//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "GraceAST.h"

namespace naylang {
StatementPtr GraceAST::operator[](int index) {
    return _nodes[index];
}

StatementPtr GraceAST::getNodeAt(int line) const {
    int index = getNodeIndexFromLine(line);
    return _nodes[index];
}

int GraceAST::getNextLine(int cur) const {
    int curIndex = getNodeIndexFromLine(cur);
    return _nodes[curIndex + 1]->line();
}

void GraceAST::addNode(StatementPtr node) {
    _nodes.push_back(node);
}

const std::vector<StatementPtr> &GraceAST::nodes() const {
    return _nodes;
}

int GraceAST::lastLine() const {
    return _nodes.back()->line();
}

int GraceAST::getNodeIndexFromLine(int line) const {
    int index = 0;
    while (index < _nodes.size()
           && _nodes[index]->line() != line) {
        index++;
    }
    return index;
}
}

