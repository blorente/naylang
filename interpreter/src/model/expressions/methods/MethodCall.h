//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_METHODCALL_H
#define NAYLANG_METHODCALL_H


#include <model/environment/Identifier.h>
#include <model/expressions/Expression.h>
#include <memory>

namespace naylang {

class MethodCall : public Expression {

    Identifier _methodName;
    std::vector<ExpressionPtr> _parameters;

public:
    MethodCall(Identifier methodName);
    MethodCall(Identifier methodName, std::vector<ExpressionPtr> parameters);

    virtual void accept(Evaluator &evaluator);

    const Identifier &getMethodName() const;
    const std::vector<ExpressionPtr> &getParameters() const;
};

} // end namespace naylang


#endif //NAYLANG_METHODCALL_H
