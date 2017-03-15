//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_VARIABLEDECLARATION_H
#define NAYLANG_VARIABLEDECLARATION_H

#include <string>
#include <model/ast/declarations/Declaration.h>

namespace naylang {

class VariableDeclaration : public Declaration {

    std::string _identifier;

public:

    VariableDeclaration(const std::string &identifier);

    virtual void accept(Evaluator &evaluator);
    const std::string &name() const;
};

}

#endif //NAYLANG_VARIABLEDECLARATION_H
