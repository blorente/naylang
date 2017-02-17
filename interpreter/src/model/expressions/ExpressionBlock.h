//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EXPRESSIONBLOCK_H
#define NAYLANG_EXPRESSIONBLOCK_H

#include <memory>
#include <vector>

#include <model/expressions/Expression.h>

namespace naylang {

#define ExpressionBlockPtr std::shared_ptr<ExpressionBlock>
class ExpressionBlock : public Expression {

    std::vector<EvaluablePtr> _expressions;

public:

    ExpressionBlock();

    virtual void accept(Evaluator &evaluator);
    void addInstruction(EvaluablePtr expression);
    const std::vector<EvaluablePtr> & expressions() const;
};
}


#endif //NAYLANG_EXPRESSIONBLOCK_H
