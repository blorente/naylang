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

    std::shared_ptr<Expression> _condition;
    std::shared_ptr<Expression> _then;
    std::shared_ptr<Expression> _else;

public:

    IfThenElse(
            std::shared_ptr<Expression> condition,
            std::shared_ptr<Expression> thenExp,
            std::shared_ptr<Expression> elseExp);

    virtual void accept(Evaluator &evaluator);
    std::shared_ptr<Expression> condition() const;
    std::shared_ptr<Expression> thenExpression() const;
    std::shared_ptr<Expression> elseExpression() const;
};
}


#endif //NAYLANG_IFTHENELSE_H
