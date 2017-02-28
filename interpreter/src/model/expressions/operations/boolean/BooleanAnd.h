//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_BOOLEANAND_H
#define NAYLANG_BOOLEANAND_H

#include <memory>
#include <model/expressions/operations/BinaryOperation.h>

namespace naylang {
class BooleanAnd : public BinaryOperation {

    ExpressionPtr _leftOperand;
    ExpressionPtr _rightOperand;

public:
    BooleanAnd(ExpressionPtr lexp, ExpressionPtr rexp);

    virtual void accept(Evaluator &evaluator);

    ExpressionPtr leftOperand() const;
    ExpressionPtr rightOperand() const;
};

} // end namespace naylang


#endif //NAYLANG_BOOLEANAND_H
