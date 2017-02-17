//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_IFTHENELSE_H
#define NAYLANG_IFTHENELSE_H

#include <memory>
#include <model/statements/Statement.h>
#include <model/expressions/primitives/Boolean.h>
#include <model/expressions/ExpressionBlock.h>

namespace naylang {
class IfThenElse : public Statement {

    ExpressionPtr _condition;
    ExpressionBlockPtr _then;
    ExpressionBlockPtr _else;

public:

    IfThenElse(
            ExpressionPtr condition,
            ExpressionBlockPtr thenExp,
            ExpressionBlockPtr elseExp);

    virtual void accept(Evaluator &evaluator);
    ExpressionPtr condition() const;
    ExpressionBlockPtr thenExpression() const;
    ExpressionBlockPtr elseExpression() const;
};
}


#endif //NAYLANG_IFTHENELSE_H
