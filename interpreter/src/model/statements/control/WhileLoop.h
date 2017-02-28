//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_FORLOOP_H
#define NAYLANG_FORLOOP_H


#include <model/statements/Statement.h>
#include <model/expressions/Expression.h>
#include <model/expressions/ExpressionBlock.h>

namespace naylang {

class WhileLoop : public Statement {

    ExpressionPtr _condition;
    ExpressionBlockPtr _body;

public:

    WhileLoop(ExpressionPtr condition, ExpressionBlockPtr body);

    virtual void accept(Evaluator &evaluator);
    ExpressionPtr condition() const;
    ExpressionBlockPtr body() const;
};

} // end namespace naylang


#endif //NAYLANG_FORLOOP_H
