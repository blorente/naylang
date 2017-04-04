//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <antlr4-runtime.h>
#include <GraceLexer.h>
#include <GraceParser.h>

#include <model/ast/ASTNodeDefinitions.h>
#include <parser/NaylangParserVisitor.h>

using namespace naylang;
using namespace antlr4;

StatementPtr translate(std::string line);

TEST_CASE("Naylang Parser Visitor", "[Parser]") {
    SECTION("Parsing an integer creates a NumberLiteral") {
        StatementPtr AST = translate("4");
        REQUIRE_NOTHROW(dynamic_cast<NumberLiteral &>(*AST));
        REQUIRE_NOTHROW(dynamic_cast<NumberLiteral &>(*AST).value() == 4);
    }

    SECTION("Parsing -4 creates an explicit request 4.prefix-") {
        StatementPtr AST = translate("-4");
        auto request = static_cast<ExplicitRequestNode &>(*AST);
        auto receiver = static_cast<NumberLiteral &>(*request.receiver());

        REQUIRE_NOTHROW(request.identifier() == "prefix-");
        REQUIRE_NOTHROW(receiver.value() == 4);
    }

}

StatementPtr translate(std::string line) {
    ANTLRInputStream stream(line);
    GraceLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);
    GraceParser parser(&tokens);
    NaylangParserVisitor parserVisitor;

    parserVisitor.visit(parser.fact());

    auto AST = parserVisitor.AST();
    return AST;
}