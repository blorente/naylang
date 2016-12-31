//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#ifndef NAYLANG_BINARYOPERATION_H
#define NAYLANG_BINARYOPERATION_H

#include <model/Expression.h>

namespace naylang {
class BinaryOperation : public Expression {

public:
    virtual void accept(Evaluator &evaluator) = 0;
    virtual ExpressionPtr leftOperand() const = 0;
    virtual ExpressionPtr rightOperand() const = 0;
};
}

#endif //NAYLANG_BINARYOPERATION_H
