//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_BLOCK_H
#define NAYLANG_BLOCK_H

#include <core/model/ast/expressions/Expression.h>
#include <core/model/ast/declarations/Declaration.h>
#include <memory>
#include <vector>

namespace naylang {

class Block;

typedef std::shared_ptr<Block> BlockPtr;

class Block : public Expression, public std::enable_shared_from_this<Block> {

    std::vector<StatementPtr> _body;
    std::vector<DeclarationPtr> _params;

public:

    Block(int line, int col);
    Block();

    void accept(Evaluator &evaluator) override;

    const std::vector<StatementPtr> &body() const;
    const std::vector<DeclarationPtr> &params() const;

    void addStatement(StatementPtr statement);
    void addParameter(DeclarationPtr param);
};

} // end namespace naylang

#endif //NAYLANG_BLOCK_H
