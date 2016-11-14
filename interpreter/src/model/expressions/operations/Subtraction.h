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

    std::shared_ptr<Expression> _leftOperand;
    std::shared_ptr<Expression> _rightOperand;

public:
    Subtraction(std::shared_ptr<Expression> lexp, std::shared_ptr<Expression> rexp);

    virtual void accept(Evaluator &evaluator);

    std::shared_ptr<Expression> leftOperand() const;
    std::shared_ptr<Expression> rightOperand() const;
};
}


#endif //NAYLANG_SUBTRACTION_H
