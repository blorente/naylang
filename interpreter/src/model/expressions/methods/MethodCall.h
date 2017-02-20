//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_METHODCALL_H
#define NAYLANG_METHODCALL_H


#include <model/environment/Identifier.h>
#include <model/expressions/Expression.h>

namespace naylang {

class MethodCall : public Expression {

    Identifier _methodName;

public:
    MethodCall(Identifier methodName);

    virtual void accept(Evaluator &evaluator);

    const Identifier &getMethodName() const;
};

} // end namespace naylang


#endif //NAYLANG_METHODCALL_H
