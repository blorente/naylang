//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EXECUTIONEVALUATOR_H
#define NAYLANG_EXECUTIONEVALUATOR_H

#include <stack>
#include <core/model/execution/Definitions.h>
#include <core/model/evaluators/Evaluator.h>

#include <core/model/ast/declarations/ConstantDeclaration.h>
#include <core/model/ast/declarations/MethodDeclaration.h>

#include <core/model/ast/expressions/Block.h>
#include <core/model/ast/expressions/ObjectConstructor.h>

#include <core/model/ast/expressions/requests/ImplicitRequestNode.h>
#include <core/model/ast/expressions/requests/ExplicitRequestNode.h>

#include <core/model/ast/expressions/primitives/BooleanLiteral.h>
#include <core/model/ast/expressions/primitives/NumberLiteral.h>
#include <core/model/ast/expressions/primitives/StringLiteral.h>

#include <core/model/ast/control/Return.h>

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
    void setScope(GraceObjectPtr scope);
    void evaluateAST(StatementPtr ast);

    virtual void evaluate(BooleanLiteral &expression);
    virtual void evaluate(NumberLiteral &expression);
    virtual void evaluate(StringLiteral &expression);
    virtual void evaluate(ImplicitRequestNode &expression);
    virtual void evaluate(ExplicitRequestNode &expression);
    virtual void evaluate(MethodDeclaration &expression);
    virtual void evaluate(ConstantDeclaration &expression);
    virtual void evaluate(Return &expression);
    virtual void evaluate(Block &expression);
    virtual void evaluate(ObjectConstructor &expression);

    void evaluate(VariableDeclaration &expression) override;
};
} // end namespace naylang

#endif //NAYLANG_EXECUTIONEVALUATOR_H
