//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_ASSIGNMENT_H
#define NAYLANG_ASSIGNMENT_H

#include <memory>
#include <model/expressions/Expression.h>

namespace naylang {

class Assignment : public Expression {

    std::string _identifier;
    ExpressionPtr _value;

public:

    Assignment(const std::string &identifier, ExpressionPtr value);

    virtual void accept(Evaluator &evaluator);
    const std::string &identifier() const;
    ExpressionPtr value() const;
};

}

#endif //NAYLANG_ASSIGNMENT_H
