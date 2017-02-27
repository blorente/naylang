//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_METHODCALL_H
#define NAYLANG_METHODCALL_H


#include <model/expressions/Expression.h>
#include <memory>
#include <model/environment/identifiers/MethodIdentifier.h>

namespace naylang {

class MethodCall : public Expression {

    std::shared_ptr<MethodIdentifier> _methodName;
    std::vector<ExpressionPtr> _parameters;

public:
    MethodCall(std::shared_ptr<MethodIdentifier> methodName);
    MethodCall(std::shared_ptr<MethodIdentifier> methodName, std::vector<ExpressionPtr> parameters);

    virtual void accept(Evaluator &evaluator);

    const MethodIdentifier &getMethodName() const;
    const std::vector<ExpressionPtr> &getParameters() const;
};

} // end namespace naylang


#endif //NAYLANG_METHODCALL_H
