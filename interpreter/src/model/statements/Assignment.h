//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_ASSIGNMENT_H
#define NAYLANG_ASSIGNMENT_H

#include <memory>
#include <model/statements/Statement.h>
#include <model/expressions/Expression.h>

namespace naylang {

class Assignment : public Statement {

    std::shared_ptr<VariableDeclaration> _declaration;
    ExpressionPtr _value;

public:

    Assignment(std::shared_ptr<VariableDeclaration> declaration, ExpressionPtr value);

    virtual void accept(Evaluator &evaluator);
    const std::string &identifier() const;
    ExpressionPtr value() const;
};

}

#endif //NAYLANG_ASSIGNMENT_H
