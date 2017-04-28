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

public:

    virtual StatementPtr operator[](int index);
    void addNode(StatementPtr node);
    void addLineLink(StatementPtr node);
    const std::vector<StatementPtr> &nodes() const;

};
}
#endif //NAYLANG_ASTTREEDEFINITION_H
