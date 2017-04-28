//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Debugger.h"

namespace naylang {

Debugger::Debugger(DebugMode *mode, const std::string &code) :
        Interpreter(std::make_unique<ExecutionEvaluator>(this)),
        _frontend{mode},
        _AST{parse(code)},
        _currentLine{1},
        _paused{true},
        _finished{false},
        _lastPause{-1}{}

void Debugger::run() {
    _finished = false;
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
            _eval->setDebugState(STOP);
        }
        while(_eval->getDebugState() == STOP) {
            _frontend->executeNextCommand();
        }
    }
}

void Debugger::step() {
    _eval->setDebugState(STEP);
}

void Debugger::skip() {
    std::cout << "Skip not yet implemented" << std::endl;
}

void Debugger::pause(Statement *node) {

}

void Debugger::finish() {
    _finished = true;
    _lastPause = -1;
    std::cout << "Process finished. Resulting environment: " << std::endl;
    std::cout << _eval->currentScope()->prettyPrint(0) << std::endl;
}
}