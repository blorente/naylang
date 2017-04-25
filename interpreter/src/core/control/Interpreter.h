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
    std::unique_ptr<ExecutionEvaluator> _eval;

public:
    Interpreter(std::unique_ptr<ExecutionEvaluator> eval) : _eval{std::move(eval)} {}
    void printResult(std::string line);

protected:
    GraceAST parse(const std::string &line) const;
    void colonize(std::string &line);
};

}
#endif //NAYLANG_INTERPRETER_H
