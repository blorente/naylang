//
// Created by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_MULTIPLICATION_H
#define NAYLANG_MULTIPLICATION_H

#include <memory>

#include <model/expressions/operations/BinaryOperation.h>

namespace naylang {
class Multiplication : public BinaryOperation {

    ExpressionPtr _leftOperand;
    ExpressionPtr _rightOperand;

public:
    Multiplication(ExpressionPtr lexp, ExpressionPtr rexp);

    virtual void accept(Evaluator &evaluator);

    ExpressionPtr leftOperand() const;
    ExpressionPtr rightOperand() const;
};
}


#endif //NAYLANG_MULTIPLICATION_H
