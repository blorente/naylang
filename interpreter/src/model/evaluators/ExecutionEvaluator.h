//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EXECUTIONEVALUATOR_H
#define NAYLANG_EXECUTIONEVALUATOR_H

#include <model/evaluators/Evaluator.h>
#include <model/ast/expressions/requests/ImplicitRequestNode.h>
#include <stack>
#include <model/execution/Definitions.h>

namespace naylang {

class ExecutionEvaluator : public Evaluator {

    GraceObjectPtr _partial;
    GraceObjectPtr _currentScope;
public:

    ExecutionEvaluator();

    const GraceObjectPtr &partial() const;
    GraceObjectPtr currentScope() const;
    GraceObjectPtr createNewScope();
    void restoreScope();

    virtual void evaluate(BooleanLiteral &expression);
    virtual void evaluate(ImplicitRequestNode &expression);
    virtual void evaluate(MethodDeclaration &expression);
};
} // end namespace naylang

#endif //NAYLANG_EXECUTIONEVALUATOR_H
