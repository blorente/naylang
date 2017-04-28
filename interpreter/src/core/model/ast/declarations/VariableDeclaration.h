//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_VARIABLEDECLARATION_H
#define NAYLANG_VARIABLEDECLARATION_H

#include <string>
#include <core/model/ast/declarations/Declaration.h>
#include <core/model/ast/expressions/Expression.h>

namespace naylang {

class VariableDeclaration : public Declaration {

    std::string _identifier;
    ExpressionPtr _initialValue;

public:

    VariableDeclaration(const std::string &identifier, ExpressionPtr intialValue, int line, int col);
    VariableDeclaration(const std::string &identifier, ExpressionPtr intialValue);
    VariableDeclaration(const std::string &identifier, int line, int col);
    VariableDeclaration(const std::string &identifier);

    virtual void accept(Evaluator &evaluator);
    const std::string &name() const;
    const ExpressionPtr &value() const;

};

}

#endif //NAYLANG_VARIABLEDECLARATION_H
