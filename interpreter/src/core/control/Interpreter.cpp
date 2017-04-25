//
// Created by borja on 4/14/17.
//

#include "REPLInterpreter.h"
#include "Interpreter.h"

namespace naylang {

void Interpreter::printResult(std::string line) {
    colonize(line);
    auto res = _eval->evaluateSandbox(parse(line));
    std::cout << res->prettyPrint(0) << std::endl;
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

void Interpreter::colonize(std::string &line) {
    if (line.at(line.length() - 1) != ';') {
        line.append(";");
    }
}
}
