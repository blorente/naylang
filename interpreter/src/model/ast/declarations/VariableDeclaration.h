//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_VARIABLEDECLARATION_H
#define NAYLANG_VARIABLEDECLARATION_H

#include <string>
#include <model/ast/declarations/Declaration.h>
#include <model/ast/expressions/Expression.h>

namespace naylang {

class VariableDeclaration : public Declaration {

    std::string _identifier;
    ExpressionPtr _initialValue;

public:

    VariableDeclaration(const std::string &identifier);
    VariableDeclaration(const std::string &identifier, ExpressionPtr intialValue);

    virtual void accept(Evaluator &evaluator);
    const std::string &name() const;
    const ExpressionPtr &value() const;
};

}

#endif //NAYLANG_VARIABLEDECLARATION_H
