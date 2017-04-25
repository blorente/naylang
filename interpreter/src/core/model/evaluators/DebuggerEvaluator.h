//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_DEBUGGEREVALUATOR_H
#define NAYLANG_DEBUGGEREVALUATOR_H

#include <core/control/Debugger.h>
#include "ExecutionEvaluator.h"

namespace naylang {

class DebuggerEvaluator : public ExecutionEvaluator {

    Debugger *_debugger;

public:

    DebuggerEvaluator(Debugger *_debugger);

    void evaluate(BooleanLiteral &expression) override;
    void evaluate(NumberLiteral &expression) override;
    void evaluate(StringLiteral &expression) override;
    void evaluate(ImplicitRequestNode &expression) override;
    void evaluate(ExplicitRequestNode &expression) override;
    void evaluate(MethodDeclaration &expression) override;
    void evaluate(ConstantDeclaration &expression) override;
    void evaluate(Return &expression) override;
    void evaluate(Block &expression) override;
    void evaluate(ObjectConstructor &expression) override;
    void evaluate(VariableDeclaration &expression) override;

private:

    void debug(Statement *node);
};
} // end namespace naylang

#endif //NAYLANG_DEBUGGEREVALUATOR_H
