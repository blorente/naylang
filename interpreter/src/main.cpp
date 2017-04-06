//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <iostream>
#include <antlr4-runtime.h>
#include <GraceLexer.h>
#include <GraceParser.h>
#include <model/evaluators/ASTPrintEvaluator.h>
#include <model/evaluators/ExecutionEvaluator.h>
#include <model/execution/objects/GraceObject.h>

#include "parser/NaylangParserVisitor.h"

using namespace naylang;
using namespace antlr4;
using namespace antlr4::tree;

void printAST(StatementPtr ast) {
    ASTPrintEvaluator eval;
    ast->accept(eval);
}

GraceObjectPtr executeAST(ExecutionEvaluator &eval, const StatementPtr AST) {
    AST->accept(eval);
    return eval.currentScope();
}

int main() {
    NaylangParserVisitor parserListener;
    ExecutionEvaluator eval;
    std::string command;
    GraceObjectPtr result;

    while (command != "quit") {
        std::cout << ">>> ";
        getline(std::cin, command);

        ANTLRInputStream line(command);
        GraceLexer lexer(&line);
        CommonTokenStream tokens(&lexer);
        GraceParser parser(&tokens);

        parserListener.visit(parser.program());
        printAST(parserListener.AST());

        result = executeAST(eval, parserListener.AST());
        std::cout << result->prettyPrint(0) << std::endl;
    }
    return 0;
}

