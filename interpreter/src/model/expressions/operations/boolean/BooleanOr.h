//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_BOOLEANOR_H
#define NAYLANG_BOOLEANOR_H

#include <memory>
#include <model/expressions/operations/BinaryOperation.h>

namespace naylang {
class BooleanOr : public BinaryOperation {

    ExpressionPtr _leftOperand;
    ExpressionPtr _rightOperand;

public:
    BooleanOr(ExpressionPtr lexp, ExpressionPtr rexp);

    virtual void accept(Evaluator &evaluator);

    ExpressionPtr leftOperand() const;
    ExpressionPtr rightOperand() const;
};

} // end namespace naylang


#endif //NAYLANG_BOOLEANOR_H
