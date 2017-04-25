//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/evaluators/DebuggerEvaluator.h>
#include "Debugger.h"

namespace naylang {

Debugger::Debugger(const std::string &code) :
        Interpreter(std::make_unique<DebuggerEvaluator>(this)),
        _AST{parse(code)},
        _currentLine{1},
        _stopped{false} {}

void Debugger::run() {
    _currentLine = 1;
    resume();
    if (!_stopped) {
        std::cout << "Process finished. Resulting environment: " << std::endl;
        std::cout << _eval->currentScope()->prettyPrint(0) << std::endl;
    }
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
    // Execute breakpoint line
    if (_stopped) { execLine(); }
    _stopped = false;
    while(!_stopped && _currentLine < _AST.lastLine()) {
        execLine();
    }
}

void Debugger::execLine() {
    _AST.getNodeAt(_currentLine)->accept(*_eval);
    _currentLine = _AST.getNextLine(_currentLine);
    if (_breakpoints.count(_currentLine) != 0) {
        std::cout << "Breakpoint found at line " << _currentLine << ". Stopping..." << std::endl;
        _stopped = true;
    }
}

bool Debugger::needsToStop(Statement *node) {
    std::cout << "Execution paused at line " << node->line() << ":" << node->col() << std::endl;
    return node->stoppable() && _stopped;
}
}