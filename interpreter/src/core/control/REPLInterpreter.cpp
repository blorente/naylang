//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "REPLInterpreter.h"

namespace naylang {
void REPLInterpreter::execute(const std::string &line) {
    eval.evaluateAST(parse(line));
    std::cout << eval.currentScope()->prettyPrint(0) << std::endl;
}
}