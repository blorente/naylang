//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Debugger.h"

namespace naylang {

Debugger::Debugger(DebugMode *mode, const std::string &code) :
        Interpreter(std::make_unique<ExecutionEvaluator>(this)),
        _frontend{mode},
        _AST{parse(code)}{}

void Debugger::run() {
    _eval->setDebugState(CONTINUE);
    _eval->evaluateAST(_AST);
    finish();
}

void Debugger::setBreakpoint(int line) {
    _breakpoints.insert(line);
    std::cout << "Breakpoint set at line " << line << std::endl;
}

void Debugger::printEnvironment() {
    std::cout << "Current environment: " << std::endl;
    std::cout << _eval->currentScope()->prettyPrint(0) << std::endl;
}

void Debugger::resume() {
    _eval->setDebugState(CONTINUE);
}

void Debugger::debug(Statement *node) {
    if (node->stoppable()) {
        if (_breakpoints.count(node->line()) != 0) {
            std::cout << "Breakpoint found at line " << node->line() << ". Stop." << std::endl;
            _eval->setDebugState(STOP);
        }
        while(_eval->getDebugState() == STOP) {
            _frontend->executeNextCommand();
        }
    }
}

void Debugger::stepIn() {
    _eval->setDebugState(STEP_IN);
}

void Debugger::stepOver() {
    _eval->setDebugState(STEP_OVER);
}

void Debugger::finish() {
    std::cout << "Process finished. Resulting environment: " << std::endl;
    std::cout << _eval->currentScope()->prettyPrint(0) << std::endl;
}
}