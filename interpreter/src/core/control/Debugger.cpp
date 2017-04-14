//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Debugger.h"

namespace naylang {

Debugger::Debugger(const std::string &code) : _AST{parse(code)} {}

void Debugger::run() {
    eval.evaluateAST(_AST);
    std::cout << eval.currentScope()->prettyPrint(0) << std::endl;
}

}