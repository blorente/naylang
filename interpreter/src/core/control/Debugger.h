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

public:

    Debugger(const std::string &filename);

};
}

#endif //NAYLANG_DEBUGGER_H
