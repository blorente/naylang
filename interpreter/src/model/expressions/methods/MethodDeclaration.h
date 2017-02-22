//
// Copyright (c) 1/5/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_METHODDECLARATION_H
#define NAYLANG_METHODDECLARATION_H


#include <model/Evaluator.h>
#include <model/environment/identifiers/MethodIdentifier.h>
#include <model/expressions/ExpressionBlock.h>

namespace naylang {
class MethodDeclaration : public Expression {

    std::unique_ptr<MethodIdentifier> _name;
    ExpressionBlockPtr _body;

public:

    MethodDeclaration(std::unique_ptr<MethodIdentifier> canonicalName, ExpressionBlockPtr body);

    virtual void accept(Evaluator &evaluator);

    const std::unique_ptr<MethodIdentifier> &getCanonName() const;
    ExpressionBlockPtr getBody() const;
};
}


#endif //NAYLANG_METHODDECLARATION_H
