//
// Copyright (c) 1/5/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_METHODDECLARATION_H
#define NAYLANG_METHODDECLARATION_H


#include <model/Evaluator.h>
#include <model/environment/Identifier.h>

namespace naylang {
class MethodDeclaration : public Expression {

    Identifier _name;
    ExpressionPtr _body;

public:

    MethodDeclaration(Identifier canonicalName, ExpressionPtr body);

    virtual void accept(Evaluator &evaluator);

    const Identifier &getCanonName() const;
    ExpressionPtr getBody() const;
};
}


#endif //NAYLANG_METHODDECLARATION_H
