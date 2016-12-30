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

    std::shared_ptr<Expression> _numerator;
    std::shared_ptr<Expression> _denominator;

public:
    Division(std::shared_ptr<Expression> numerator, std::shared_ptr<Expression> denominator);

    virtual void accept(Evaluator &evaluator);

    std::shared_ptr<Expression> leftOperand() const;
    std::shared_ptr<Expression> rightOperand() const;
    std::shared_ptr<Expression> numerator() const;
    std::shared_ptr<Expression> denominator() const;
};
}


#endif //NAYLANG_DIVISION_H
