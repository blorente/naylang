//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "DebuggerEvaluator.h"

namespace naylang {

DebuggerEvaluator::DebuggerEvaluator(Debugger *_debugger) : _debugger(_debugger) {}

void DebuggerEvaluator::evaluate(BooleanLiteral &expression) {
    debug(&expression);
    ExecutionEvaluator::evaluate(expression);
}

void DebuggerEvaluator::evaluate(NumberLiteral &expression) {
    debug(&expression);
    ExecutionEvaluator::evaluate(expression);
}

void DebuggerEvaluator::evaluate(StringLiteral &expression) {
    debug(&expression);
    ExecutionEvaluator::evaluate(expression);
}

void DebuggerEvaluator::evaluate(ImplicitRequestNode &expression) {
    debug(&expression);
    ExecutionEvaluator::evaluate(expression);
}

void DebuggerEvaluator::evaluate(ExplicitRequestNode &expression) {
    debug(&expression);
    ExecutionEvaluator::evaluate(expression);
}

void DebuggerEvaluator::evaluate(MethodDeclaration &expression) {
    debug(&expression);
    ExecutionEvaluator::evaluate(expression);
}

void DebuggerEvaluator::evaluate(ConstantDeclaration &expression) {
    debug(&expression);
    ExecutionEvaluator::evaluate(expression);
}

void DebuggerEvaluator::evaluate(Return &expression) {
    debug(&expression);
    ExecutionEvaluator::evaluate(expression);
}

void DebuggerEvaluator::evaluate(Block &expression) {
    debug(&expression);
    ExecutionEvaluator::evaluate(expression);
}

void DebuggerEvaluator::evaluate(ObjectConstructor &expression) {
    debug(&expression);
    ExecutionEvaluator::evaluate(expression);
}

void DebuggerEvaluator::evaluate(VariableDeclaration &expression) {
    debug(&expression);
    ExecutionEvaluator::evaluate(expression);
}

void DebuggerEvaluator::debug(Statement *node) {
    _debugger->debug(node);
}
}