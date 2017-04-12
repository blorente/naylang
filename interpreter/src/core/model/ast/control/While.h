//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_WHILE_H
#define NAYLANG_WHILE_H

#include <core/model/ast/Statement.h>
#include <core/model/ast/expressions/Block.h>
#include <bits/shared_ptr.h>
#include <memory>

namespace naylang {

class While : public Statement {

    BlockPtr _condition;
    BlockPtr _body;

public:
    While(BlockPtr condition, BlockPtr body, int line, int col);
    While(BlockPtr condition, BlockPtr body);

    void accept(Evaluator &evaluator) override;

    const std::shared_ptr<Block> &condition() const;
    const std::shared_ptr<Block> &body() const;
};

} // end namespace naylang

#endif //NAYLANG_WHILE_H
