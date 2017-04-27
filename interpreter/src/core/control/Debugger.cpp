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
    _currentLine = 1;
    resume();
    if (!_paused) {
        finish();
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
    bool wasPaused = _paused;
    _paused = false;
    if (wasPaused) { execLine(); }
    while(!_paused && _currentLine <= _AST.lastLine()) {
        execLine();
    }
}

bool Debugger::debug(Statement *node) {
    if (!node->stoppable())
        return false;

    if (_breakpoints.count(node->line()) == 0)
        return false;

    if (node->line() == _lastPause)
        return false;

    pause(node);
    return true;
}

void Debugger::step() {
    assert(_paused);
    if (_currentLine > _AST.lastLine()) {
        finish();
    } else {
        execLine();
    }
}

void Debugger::skip() {
    assert(_paused);
    std::cout << "Skip not yet implemented" << std::endl;
}

void Debugger::pause(Statement *node) {
    // We notify the pause
    std::cout << "Debugger paused at " << node->line() << ":" << node->col() << std::endl;
    // Wait for commands?
    _paused = true;
    _lastPause = node->line();
    _currentLine = node->line();
    while(_paused) {
        _frontend->executeNextCommand();
    }
}

void Debugger::execLine() {
    Statement *curNode = _AST.getNodeAt(_currentLine).get();
    curNode->accept(*_eval);
    _currentLine = _AST.getNextLine(_currentLine, false);
}

void Debugger::finish() {
    _finished = true;
    _lastPause = -1;
    std::cout << "Process finished. Resulting environment: " << std::endl;
    std::cout << _eval->currentScope()->prettyPrint(0) << std::endl;
}
}