//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EXPRESSION_H
#define NAYLANG_EXPRESSION_H

#include <model/ast/Statement.h>

namespace  naylang {

class Expression;

typedef std::shared_ptr<Expression> ExpressionPtr;

class Expression : public Statement {
public:

    virtual void accept(Evaluator &evaluator) = 0;
};
}

#endif //NAYLANG_EXPRESSION_H
