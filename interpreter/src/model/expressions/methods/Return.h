//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_RETURN_H
#define NAYLANG_RETURN_H

#include <model/expressions/Expression.h>
#include <memory>

namespace naylang {

class Return : Expression {

    ExpressionPtr _expression;

public:
    Return(ExpressionPtr declaration);

    virtual void accept(Evaluator &evaluator);
    ExpressionPtr expression() const;
};

} // end namespace naylang


#endif //NAYLANG_RETURN_H
