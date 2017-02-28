//
// Created by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_DIVISION_H
#define NAYLANG_DIVISION_H

#include <memory>

#include <model/expressions/operations/BinaryOperation.h>

namespace naylang {
class Division : public BinaryOperation {

    ExpressionPtr _numerator;
    ExpressionPtr _denominator;

public:
    Division(ExpressionPtr numerator, ExpressionPtr denominator);

    virtual void accept(Evaluator &evaluator);

    ExpressionPtr leftOperand() const;
    ExpressionPtr rightOperand() const;
    ExpressionPtr numerator() const;
    ExpressionPtr denominator() const;
};
}


#endif //NAYLANG_DIVISION_H
