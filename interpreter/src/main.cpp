//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <iostream>
#include <antlr4-runtime.h>
#include <GraceLexer.h>
#include <GraceParser.h>
#include <model/evaluators/ASTPrintEvaluator.h>

#include "parser/NaylangParserVisitor.h"

using namespace naylang;
using namespace antlr4;
using namespace antlr4::tree;

void printAST(StatementPtr ast) {
    ASTPrintEvaluator eval;
    ast->accept(eval);
}

int main() {
    NaylangParserVisitor parserListener;
    std::string command;

    while (command != "quit") {
        std::cout << ">>> ";
        getline(std::cin, command);

        ANTLRInputStream line(command);
        GraceLexer lexer(&line);
        CommonTokenStream tokens(&lexer);
        GraceParser parser(&tokens);

        parserListener.visit(parser.program());
        printAST(parserListener.AST());
    }
    return 0;
}

