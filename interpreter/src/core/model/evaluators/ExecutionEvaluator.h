//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EXECUTIONEVALUATOR_H
#define NAYLANG_EXECUTIONEVALUATOR_H

#include <stack>
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
#include <core/model/ast/ASTTreeDefinition.h>
#include <core/model/execution/objects/GraceObject.h>

namespace naylang {

class GraceObject;

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
    void evaluateAST(const GraceAST &ast);
    GraceObjectPtr evaluateSandbox(const GraceAST &ast);

    virtual void evaluate(BooleanLiteral &expression) override;
    virtual void evaluate(NumberLiteral &expression) override;
    virtual void evaluate(StringLiteral &expression) override;
    virtual void evaluate(ImplicitRequestNode &expression) override;
    virtual void evaluate(ExplicitRequestNode &expression) override;
    virtual void evaluate(MethodDeclaration &expression) override;
    virtual void evaluate(ConstantDeclaration &expression) override;
    virtual void evaluate(Return &expression) override;
    virtual void evaluate(Block &expression) override;
    virtual void evaluate(ObjectConstructor &expression) override;
    virtual void evaluate(VariableDeclaration &expression) override;
};
} // end namespace naylang

#endif //NAYLANG_EXECUTIONEVALUATOR_H
