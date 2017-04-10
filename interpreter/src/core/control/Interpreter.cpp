//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Interpreter.h"

namespace naylang {
void Interpreter::execute(const std::string &line) {
    eval.evaluateAST(parse(line));
    std::cout << eval.currentScope()->prettyPrint(0) << std::endl;
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