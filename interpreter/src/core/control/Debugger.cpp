//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/evaluators/DebugEvaluator.h>
#include "Debugger.h"

namespace naylang {

Debugger::Debugger(DebugMode *mode, const std::string &code) :
    _debugEval{std::make_unique<DebugEvaluator>(this)},
    Interpreter(_debugEval.get()),
    _frontend{mode},
    _AST{parse(code)}{
    _eval = _debugEval.get();
}

void Debugger::run() {
    _debugEval->setDebugState(CONTINUE);
    _debugEval->evaluateAST(_AST);
    finish();
}

void Debugger::setBreakpoint(int line) {
    _breakpoints.insert(line);
    std::cout << "Breakpoint set at line " << line << std::endl;
}

void Debugger::printEnvironment() {
    std::cout << "Current environment: " << std::endl;
    std::cout << _debugEval->currentScope()->prettyPrint(0) << std::endl;
}

void Debugger::resume() {
    _debugEval->setDebugState(CONTINUE);
}

void Debugger::debug(Statement *node) {
    if (node->stoppable()) {
        if (_breakpoints.count(node->line()) != 0) {
            std::cout << "Breakpoint found at line " << node->line() << ". Stop." << std::endl;
            _debugEval->setDebugState(STOP);
        }
        while(_debugEval->getDebugState() == STOP) {
            _frontend->executeNextCommand();
        }
    }
}

void Debugger::stepIn() {
    _debugEval->setDebugState(STEP_IN);
}

void Debugger::stepOver() {
    _debugEval->setDebugState(STEP_OVER);
}

void Debugger::finish() {
    std::cout << "Process finished. Resulting environment: " << std::endl;
    std::cout << _debugEval->currentScope()->prettyPrint(0) << std::endl;
}
}