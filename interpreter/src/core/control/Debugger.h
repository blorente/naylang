//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_DEBUGGER_H
#define NAYLANG_DEBUGGER_H

#include "Interpreter.h"

namespace naylang {
class Debugger : public Interpreter {

    GraceAST _AST;
    std::set<int> _breakpoints;
    int _currentLine;
    bool _stopped;

public:

    Debugger(const std::string &filename);

    void run();
    void setBreakpoint(int line);
    void printEnvironment();
    void resume();
    void execLine();
};
}

#endif //NAYLANG_DEBUGGER_H
