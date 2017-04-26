//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_ASTTREEDEFINITION_H
#define NAYLANG_ASTTREEDEFINITION_H

#include <core/model/ast/ASTNodeDefinitions.h>
#include <map>

namespace naylang {
class GraceAST {
    std::vector<StatementPtr> _nodes;
    std::map<int, StatementPtr> _nodeLinks;
    int _lastLine = 0;
    StatementPtr _lastAdded = nullptr;

public:

    virtual StatementPtr operator[](int index);
    StatementPtr getNodeAt(int line) const;
    void addNode(StatementPtr node);
    int getNextLine(int curLine, bool stepIn);
    void addLineLink(StatementPtr node);
    const std::vector<StatementPtr> &nodes() const;
    int lastLine() const;

};
}
#endif //NAYLANG_ASTTREEDEFINITION_H
