//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_INTERPRETER_H
#define NAYLANG_INTERPRETER_H

#include <core/model/evaluators/ExecutionEvaluator.h>
#include <core/model/execution/objects/GraceObject.h>
#include <GraceLexer.h>

using namespace antlr4;
using namespace antlr4::tree;

namespace naylang {
class Interpreter {
protected:
    ExecutionEvaluator eval;

public:
    void printResult(const std::string &line);

protected:
    GraceAST parse(const std::string &line) const;
};

}
#endif //NAYLANG_INTERPRETER_H
