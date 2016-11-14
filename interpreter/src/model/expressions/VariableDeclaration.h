//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_VARIABLEDECLARATION_H
#define NAYLANG_VARIABLEDECLARATION_H

#include <model/Expression.h>
#include <string>

namespace naylang {

class VariableDeclaration : public Expression {

    std::string _identifier;

public:

    VariableDeclaration(const std::string &identifier);

    virtual void accept(Evaluator &evaluator);
    const std::string &identifier() const;
};

}

#endif //NAYLANG_VARIABLEDECLARATION_H
