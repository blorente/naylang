//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_DEBUGGER_H
#define NAYLANG_DEBUGGER_H

#include <frontends/modes/debug/DebugMode.h>
#include <core/control/DebugState.h>
#include "Interpreter.h"

namespace naylang {
class DebugMode;
class Debugger : public Interpreter {

    GraceAST _AST;
    std::set<int> _breakpoints;
    DebugMode *_frontend;

public:

    Debugger(DebugMode *frontend, const std::string &filename);

    void run();
    void setBreakpoint(int line);
    void printEnvironment();
    void resume();
    void step();
    void skip();

    void debug(Statement *node);

private:

    void finish();
};
}

#endif //NAYLANG_DEBUGGER_H
