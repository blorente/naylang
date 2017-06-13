//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_DEBUGEVALUATOR_H
#define NAYLANG_DEBUGEVALUATOR_H


#include <core/control/Debugger.h>

namespace naylang {

class DebugEvaluator : public ExecutionEvaluator {

    Debugger *_debugger;
    bool _debugging;
    DebugState _state;

public:
    DebugEvaluator(Debugger *debugger);

    void evaluate(ImplicitRequestNode &expression) override;
    void evaluate(ExplicitRequestNode &expression) override;
    void evaluate(ConstantDeclaration &expression) override;
    void evaluate(VariableDeclaration &expression) override;

    // Debug Methods
    void setDebugState(DebugState state);
    DebugState getDebugState() const;

private:
    void beginDebug(Statement *node);
    void endDebug(Statement *node, DebugState prevState);
};
} // end namespace naylang

#endif //NAYLANG_DEBUGEVALUATOR_H
