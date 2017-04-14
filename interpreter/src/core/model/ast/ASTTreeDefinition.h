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

    StatementPtr getLine(int line) {
        int stat = 0;
        while (stat < _nodes.size()
               && _nodes[stat]->line() < line) {
            stat++;
        }
        return _nodes[stat];
    }

    void addNode(StatementPtr node) {
        _nodes.push_back(node);
    }

    const std::vector<StatementPtr> &nodes() const {
        return _nodes;
    }
};
}
#endif //NAYLANG_ASTTREEDEFINITION_H
