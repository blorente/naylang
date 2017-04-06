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

GraceObjectPtr executeAST(const StatementPtr AST) {
    ExecutionEvaluator eval;
    AST->accept(eval);
    return eval.partial();
}

int main() {
    NaylangParserVisitor parserListener;
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

        result = executeAST(parserListener.AST());
    }
    return 0;
}

