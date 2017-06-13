//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "DebugEvaluator.h"

namespace naylang {

void DebugEvaluator::beginDebug(Statement *node) {
    if (!_debugging)
        return;

    if (_state == STEP_OVER)
        _state = CONTINUE;

    _debugger->debug(node);
}

void DebugEvaluator::endDebug(Statement *node, DebugState prevState) {
    if (!_debugging)
        return;

    if (!node->stoppable())
        return;

    if (prevState == STEP_OVER)
        _state = STOP;

    if (_state == STEP_IN)
        _state = STOP;
}

void DebugEvaluator::evaluate(ImplicitRequestNode &expression) {
    beginDebug(&expression);
    ExecutionEvaluator::evaluate(expression);
}

void DebugEvaluator::evaluate(ExplicitRequestNode &expression) {
    beginDebug(&expression);
    ExecutionEvaluator::evaluate(expression);
    endDebug(&expression, STEP_OVER_SKIP);
}

void DebugEvaluator::evaluate(ConstantDeclaration &expression) {
    beginDebug(&expression);
    DebugState prevState = _state;
    ExecutionEvaluator::evaluate(expression);
    endDebug(&expression, prevState);
}

void DebugEvaluator::evaluate(VariableDeclaration &expression) {
    beginDebug(&expression);
    DebugState prevState = _state;
    ExecutionEvaluator::evaluate(expression);
    endDebug(&expression, prevState);
}

void DebugEvaluator::setDebugState(DebugState state) {
    _state = state;
}

DebugState DebugEvaluator::getDebugState() const {
    return _state;
}

DebugEvaluator::DebugEvaluator(Debugger *debugger) : ExecutionEvaluator() {
    _debugger = debugger;
    _state = STOP;
}

}