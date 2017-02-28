//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_METHODCALL_H
#define NAYLANG_METHODCALL_H


#include <model/expressions/Expression.h>
#include <model/statements/methods/MethodDeclaration.h>
#include <memory>
#include <vector>

namespace naylang {

class MethodCall : public Expression {

    std::shared_ptr<MethodDeclaration> _declaration;
    std::vector<std::shared_ptr<Assignment>> _parameters;

public:
    MethodCall(std::shared_ptr<MethodDeclaration> declaration);
    MethodCall(std::shared_ptr<MethodDeclaration> declaration, std::vector<std::shared_ptr<Assignment>> parameters);

    virtual void accept(Evaluator &evaluator);

    const std::shared_ptr<MethodIdentifier> & getMethodName() const;
    const std::shared_ptr<MethodDeclaration> & declaration() const;
    const std::vector<std::shared_ptr<Assignment>> &getParameters() const;
};

} // end namespace naylang


#endif //NAYLANG_METHODCALL_H
