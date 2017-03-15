//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_BLOCK_H
#define NAYLANG_BLOCK_H

#include <model/ast/expressions/Expression.h>
#include <model/ast/declarations/Declaration.h>
#include <memory>
#include <vector>

namespace naylang {

class Block;

typedef std::shared_ptr<Block> BlockPtr;

class Block : public Expression {

    std::vector<StatementPtr> _body;
    std::vector<DeclarationPtr> _params;

public:

    Block() = default;

    void accept(Evaluator &evaluator) override;

    const std::vector<StatementPtr> &body() const;
    const std::vector<DeclarationPtr> &params() const;

    void addStatement(StatementPtr statement);
    void addParameter(DeclarationPtr param);
};

} // end namespace naylang

#endif //NAYLANG_BLOCK_H
