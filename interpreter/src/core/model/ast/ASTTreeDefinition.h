//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_ASTTREEDEFINITION_H
#define NAYLANG_ASTTREEDEFINITION_H

#include <core/model/ast/ASTNodeDefinitions.h>

namespace naylang {
class GraceAST {

    std::vector<StatementPtr> _nodes;
public:

    virtual StatementPtr operator[](int index) {
        return _nodes[index];
    }

    StatementPtr getNodeAt(int line) const {
        int index = getNodeIndexFromLine(line);
        return _nodes[index];
    }

    int getNextLine(int cur) const {
        int curIndex = getNodeIndexFromLine(cur);
        return _nodes[curIndex + 1]->line();
    }

    void addNode(StatementPtr node) {
        _nodes.push_back(node);
    }

    const std::vector<StatementPtr> &nodes() const {
        return _nodes;
    }

    int lastLine() const {
        return _nodes.back()->line();
    }

private:

    int getNodeIndexFromLine(int line) const {
        int index = 0;
        while (index < _nodes.size()
               && _nodes[index]->line() != line) {
            index++;
        }
        return index;
    }
};
}
#endif //NAYLANG_ASTTREEDEFINITION_H
