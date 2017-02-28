//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_VARIABLEREFERENCE_H
#define NAYLANG_VARIABLEREFERENCE_H

#include <string>
#include <model/expressions/Expression.h>
#include <memory>

namespace naylang {

class VariableReference : public Expression {

    std::shared_ptr<VariableDeclaration> _declaration;

public:

    VariableReference(std::shared_ptr<VariableDeclaration> declaration);
    VariableReference(const std::string &constIdentifier);

    virtual void accept(Evaluator &evaluator);
    const std::string &identifier() const;
};

}


#endif //NAYLANG_VARIABLEREFERENCE_H
