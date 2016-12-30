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

    std::shared_ptr<Expression> _leftOperand;
    std::shared_ptr<Expression> _rightOperand;

public:
    Multiplication(std::shared_ptr<Expression> lexp, std::shared_ptr<Expression> rexp);

    virtual void accept(Evaluator &evaluator);

    std::shared_ptr<Expression> leftOperand() const;
    std::shared_ptr<Expression> rightOperand() const;
};
}


#endif //NAYLANG_MULTIPLICATION_H
