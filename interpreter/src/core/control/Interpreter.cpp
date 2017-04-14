//
// Created by borja on 4/14/17.
//

#include "REPLInterpreter.h"
#include "Interpreter.h"

namespace naylang {
void Interpreter::execute(const std::__cxx11::string &line) {
    eval.evaluateAST(parse(line));
    std::cout << eval.currentScope()->prettyPrint(0) << std::endl;
}

void Interpreter::printResult(const std::__cxx11::string &line) {
    eval.evaluateAST(parse(line));
    std::cout << eval.partial()->prettyPrint(0) << std::endl;
}

GraceAST Interpreter::parse(const std::__cxx11::string &line) const {
    ANTLRInputStream stream(line);
    GraceLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);
    GraceParser parser(&tokens);
    NaylangParserVisitor parserVisitor;
    parserVisitor.visit(parser.program());
    return parserVisitor.AST();
}
}
