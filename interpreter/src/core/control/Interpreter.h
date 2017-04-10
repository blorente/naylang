//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_INTERPRETER_H
#define NAYLANG_INTERPRETER_H

#include <core/parser/NaylangParserVisitor.h>
#include <core/model/evaluators/ExecutionEvaluator.h>
#include <core/model/execution/objects/GraceObject.h>
#include <GraceLexer.h>

using namespace antlr4;
using namespace antlr4::tree;

namespace naylang {
class Interpreter {

    ExecutionEvaluator eval;

public:

    void execute(const std::string &line);
    GraceAST parse(const std::string &line) const;
};
}

#endif //NAYLANG__INTERPRETER_H
