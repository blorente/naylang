//
// Created by borja on 4/14/17.
//

#include "REPLInterpreter.h"
#include "Interpreter.h"

namespace naylang {

void Interpreter::printResult(const std::string &line) {
    eval.evaluateAST(parse(line));
    std::cout << eval.partial()->prettyPrint(0) << std::endl;
}

GraceAST Interpreter::parse(const std::string &line) const {
    ANTLRInputStream stream(line);
    GraceLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);
    GraceParser parser(&tokens);
    NaylangParserVisitor parserVisitor;
    parserVisitor.visit(parser.program());
    return parserVisitor.AST();
}
}
