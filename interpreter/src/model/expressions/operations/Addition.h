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

    std::shared_ptr<Expression> _leftOperand;
    std::shared_ptr<Expression> _rightOperand;

public:
    Addition(std::shared_ptr<Expression> lexp, std::shared_ptr<Expression> rexp);

    virtual void accept(Evaluator &evaluator);

    std::shared_ptr<Expression> leftOperand() const;
    std::shared_ptr<Expression> rightOperand() const;
};
}

#endif //NAYLANG_ADDITION_H
