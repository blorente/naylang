//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_IFTHENELSE_H
#define NAYLANG_IFTHENELSE_H

#include <memory>
#include <model/ast/Statement.h>
#include <model/ast/expressions/Block.h>

namespace naylang {
class IfThen : public Statement {

    ExpressionPtr _condition;
    BlockPtr _then;

public:

    IfThen(
            ExpressionPtr condition,
            BlockPtr thenExp);

    virtual void accept(Evaluator &evaluator);
    ExpressionPtr condition() const;
    BlockPtr thenExpression() const;
};
}


#endif //NAYLANG_IFTHENELSE_H
