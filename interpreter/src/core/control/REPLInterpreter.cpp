//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "REPLInterpreter.h"
#include <core/control/Debugger.h>

namespace naylang {
void REPLInterpreter::execute(std::string line) {
    colonize(line);
    _replEval->evaluateAST(parse(line));
    std::cout << _replEval->currentScope()->prettyPrint(0) << std::endl;
}

REPLInterpreter::REPLInterpreter() :
        _replEval{std::make_unique<ExecutionEvaluator>()},
        Interpreter(_replEval.get()) {}
}