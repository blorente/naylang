//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_CONSTANT_H
#define NAYLANG_CONSTANT_H

#include <memory>
#include <model/statements/Statement.h>
#include <model/expressions/Expression.h>

namespace naylang {

class Constant : public Statement {

    std::string _identifier;
    ExpressionPtr _value;

public:

    Constant(const std::string &identifier, ExpressionPtr value);

    virtual void accept(Evaluator &evaluator);
    const std::string &identifier() const;
    ExpressionPtr value() const;
};

}

#endif //NAYLANG_CONSTANT_H
