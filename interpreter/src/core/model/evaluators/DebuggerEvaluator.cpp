//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "DebuggerEvaluator.h"

namespace naylang {

DebuggerEvaluator::DebuggerEvaluator(Debugger *_debugger) : _debugger(_debugger) {}

void DebuggerEvaluator::evaluate(BooleanLiteral &expression) {
    if (!stop(&expression)) {
        ExecutionEvaluator::evaluate(expression);
    }
}

void DebuggerEvaluator::evaluate(NumberLiteral &expression) {
    if (!stop(&expression)) {
        ExecutionEvaluator::evaluate(expression);
    }
}

void DebuggerEvaluator::evaluate(StringLiteral &expression) {
    if (!stop(&expression)) {
        ExecutionEvaluator::evaluate(expression);
    }
}

void DebuggerEvaluator::evaluate(ImplicitRequestNode &expression) {
    if (!stop(&expression)) {
        ExecutionEvaluator::evaluate(expression);
    }
}

void DebuggerEvaluator::evaluate(ExplicitRequestNode &expression) {
    if (!stop(&expression)) {
        ExecutionEvaluator::evaluate(expression);
    }
}

void DebuggerEvaluator::evaluate(MethodDeclaration &expression) {
    if (!stop(&expression)) {
        ExecutionEvaluator::evaluate(expression);
    }
}

void DebuggerEvaluator::evaluate(ConstantDeclaration &expression) {
    if (!stop(&expression)) {
        ExecutionEvaluator::evaluate(expression);
    }
}

void DebuggerEvaluator::evaluate(Return &expression) {
    if (!stop(&expression)) {
        ExecutionEvaluator::evaluate(expression);
    }
}

void DebuggerEvaluator::evaluate(Block &expression) {
    if (!stop(&expression)) {
        ExecutionEvaluator::evaluate(expression);
    }
}

void DebuggerEvaluator::evaluate(ObjectConstructor &expression) {
    if (!stop(&expression)) {
        ExecutionEvaluator::evaluate(expression);
    }
}

void DebuggerEvaluator::evaluate(VariableDeclaration &expression) {
    if (!stop(&expression)) {
        ExecutionEvaluator::evaluate(expression);
    }
}

bool DebuggerEvaluator::stop(Statement *node) {
    return _debugger->needsToStop(node);
}
}