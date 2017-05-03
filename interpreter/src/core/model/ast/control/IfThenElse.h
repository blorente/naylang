//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_IFTHENELSE_H
#define NAYLANG_IFTHENELSE_H

#include <memory>
#include <core/model/ast/Statement.h>
#include <core/model/ast/expressions/Block.h>

namespace naylang {
class IfThenElse : public Statement {

    ExpressionPtr _condition;
    std::vector<StatementPtr> _then;
    std::vector<StatementPtr> _else;

public:

    IfThenElse(
            ExpressionPtr condition,
            std::vector<StatementPtr> thenExp,
            std::vector<StatementPtr> elseExp,
            int line, int col);
    IfThenElse(
            ExpressionPtr condition,
            std::vector<StatementPtr> thenExp,
            std::vector<StatementPtr> elseExp);

    virtual void accept(Evaluator &evaluator);
    ExpressionPtr condition() const;
    const std::vector<StatementPtr> &thenPart() const;
    const std::vector<StatementPtr> &elsePart() const;
};
}


#endif //NAYLANG_IFTHENELSE_H
