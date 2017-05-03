//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EXECUTIONEVALUATOR_H
#define NAYLANG_EXECUTIONEVALUATOR_H

#include <stack>
#include <core/model/evaluators/Evaluator.h>
#include <core/model/ast/ASTNodeDefinitions.h>
#include <core/model/ast/GraceAST.h>
#include <core/model/execution/objects/GraceObject.h>
#include <core/control/DebugState.h>

namespace naylang {

class GraceObject;
class Debugger;

class ExecutionEvaluator : public Evaluator {

    GraceObjectPtr _partial;
    GraceObjectPtr _currentScope;

    Debugger *_debugger;
    bool _debugging;

    DebugState _state;

public:

    ExecutionEvaluator();

    ExecutionEvaluator(Debugger *debugger);
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
    virtual void evaluate(Assignment &expression) override;
    void evaluate(IfThen &expression) override;
    void evaluate(IfThenElse &expression) override;

    void evaluate(While &expression) override;

    // Debug Methods
    void setDebugState(DebugState state);
    DebugState getDebugState() const;

private:
    void beginDebug(Statement *node);
    void endDebug(Statement *node, DebugState prevState);

    template <typename T, typename... Args>
    std::shared_ptr<T> create_obj(Args&&...args) {
        std::shared_ptr<T> obj = make_obj<T>(std::forward<Args>(args)...);
        obj->setField("self", obj);
        return obj;
    };
};
} // end namespace naylang

#endif //NAYLANG_EXECUTIONEVALUATOR_H
