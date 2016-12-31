//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EXPRESSIONBLOCK_H
#define NAYLANG_EXPRESSIONBLOCK_H

#include <memory>
#include <vector>

#include <model/Expression.h>

namespace naylang {
class ExpressionBlock : public Expression {

    std::vector<std::shared_ptr<Expression>> _expressions;

public:

    ExpressionBlock();

    virtual void accept(Evaluator &evaluator);
    void addExpression(std::shared_ptr<Expression> expression);
    const std::vector<std::shared_ptr<Expression>> & expressions() const;
};
}


#endif //NAYLANG_EXPRESSIONBLOCK_H
