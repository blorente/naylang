//
// Copyright (c) 1/5/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_METHODDECLARATION_H
#define NAYLANG_METHODDECLARATION_H


#include <model/Evaluator.h>
#include <model/statements/Statement.h>
#include <model/environment/identifiers/MethodIdentifier.h>
#include <model/expressions/ExpressionBlock.h>

namespace naylang {
class MethodDeclaration : public Statement {

    std::shared_ptr<MethodIdentifier> _name;
    ExpressionBlockPtr _body;

public:

    MethodDeclaration(std::shared_ptr<MethodIdentifier> canonicalName, ExpressionBlockPtr body);

    virtual void accept(Evaluator &evaluator);

    const std::shared_ptr<MethodIdentifier> &getCanonName() const;
    ExpressionBlockPtr getBody() const;
};
}


#endif //NAYLANG_METHODDECLARATION_H
