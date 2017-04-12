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
    BlockPtr _then;
    BlockPtr _else;

public:

    IfThenElse(
            ExpressionPtr condition,
            BlockPtr thenExp,
            BlockPtr elseExp);

    virtual void accept(Evaluator &evaluator);
    ExpressionPtr condition() const;
    BlockPtr thenExpression() const;
    BlockPtr elseExpression() const;
};
}


#endif //NAYLANG_IFTHENELSE_H
