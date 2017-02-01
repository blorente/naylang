//
// Created by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_SUBTRACTION_H
#define NAYLANG_SUBTRACTION_H

#include <memory>

#include <model/expressions/operations/BinaryOperation.h>

namespace naylang {
class Subtraction : public BinaryOperation {

    ExpressionPtr _leftOperand;
    ExpressionPtr _rightOperand;

public:
    Subtraction(ExpressionPtr lexp, ExpressionPtr rexp);

    virtual void accept(Evaluator &evaluator);

    ExpressionPtr leftOperand() const;
    ExpressionPtr rightOperand() const;
};
}


#endif //NAYLANG_SUBTRACTION_H
