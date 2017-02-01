//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_IFTHENELSE_H
#define NAYLANG_IFTHENELSE_H

#include <memory>

#include <model/Expression.h>
#include <model/expressions/primitives/Boolean.h>

namespace naylang {
class IfThenElse : public Expression {

    ExpressionPtr _condition;
    ExpressionPtr _then;
    ExpressionPtr _else;

public:

    IfThenElse(
            ExpressionPtr condition,
            ExpressionPtr thenExp,
            ExpressionPtr elseExp);

    virtual void accept(Evaluator &evaluator);
    ExpressionPtr condition() const;
    ExpressionPtr thenExpression() const;
    ExpressionPtr elseExpression() const;
};
}


#endif //NAYLANG_IFTHENELSE_H
