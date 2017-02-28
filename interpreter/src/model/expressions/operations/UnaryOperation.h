//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_UNARYOPERATION_H
#define NAYLANG_UNARYOPERATION_H

#include <model/expressions/Expression.h>

namespace naylang {

class UnaryOperation : public Expression {
public:
    virtual void accept(Evaluator &evaluator) = 0;
    virtual ExpressionPtr operand() const = 0;
};

} // end namespace naylang


#endif //NAYLANG_UNARYOPERATION_H
