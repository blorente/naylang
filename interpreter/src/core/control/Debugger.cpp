//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Debugger.h"

namespace naylang {

Debugger::Debugger(const std::string &code) : _AST{parse(code)}, _currentLine{-1} {}

void Debugger::run() {
    _currentLine = 1;
    while(_breakpoints.count(_currentLine) == 0) {
        _AST.getLine(_currentLine)->accept(eval);
        _currentLine++;
    }
    if (_breakpoints.count(_currentLine) != 0) {
        std::cout << "Breakpoint found at line " << _currentLine << ". Stopping..." << std::endl;
    } else {
        std::cout << "Process finished. Resulting environment: " << std::endl;
        std::cout << eval.currentScope()->prettyPrint(0) << std::endl;
    }
}

void Debugger::setBreakpoint(int line) {
    _breakpoints.insert(line);
    std::cout << "Breakpoint set at line " << line << std::endl;
}

}