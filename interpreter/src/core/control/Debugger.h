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

public:

    Debugger(const std::string &filename);

    void run();
    void setBreakpoint(int line);

};
}

#endif //NAYLANG_DEBUGGER_H
