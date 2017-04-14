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

    virtual StatementPtr operator[](int index);
    StatementPtr getNodeAt(int line) const;
    int getNextLine(int cur) const;
    void addNode(StatementPtr node);
    const std::vector<StatementPtr> &nodes() const;
    int lastLine() const;

private:
    int getNodeIndexFromLine(int line) const;
};
}
#endif //NAYLANG_ASTTREEDEFINITION_H
