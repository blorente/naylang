//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#ifndef NAYLANG_ADDITION_H
#define NAYLANG_ADDITION_H

#include <memory>

#include <model/expressions/operations/BinaryOperation.h>

namespace naylang {

class Addition : public BinaryOperation {

    ExpressionPtr _leftOperand;
    ExpressionPtr _rightOperand;

public:
    Addition(ExpressionPtr lexp, ExpressionPtr rexp);

    virtual void accept(Evaluator &evaluator);

    ExpressionPtr leftOperand() const;
    ExpressionPtr rightOperand() const;
};
}

#endif //NAYLANG_ADDITION_H
