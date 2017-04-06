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
    SECTION("Parsing -4 creates an explicit request 4.prefix-") {
        StatementPtr AST = translate("-4\n");
        auto request = static_cast<ExplicitRequestNode &>(*AST);
        auto receiver = static_cast<NumberLiteral &>(*request.receiver());

        REQUIRE_NOTHROW(request.identifier() == "prefix-");
        REQUIRE_NOTHROW(receiver.value() == 4);
    }

    SECTION("Parsing 4 + 5 * 6 create the explicit request 4.+(5.*(6))") {
        StatementPtr AST = translate("4 + 5 * 6\n");
        auto request = static_cast<ExplicitRequestNode &>(*AST);
        auto four = static_cast<NumberLiteral &>(*request.receiver());
        auto subrequest = static_cast<ExplicitRequestNode &>(*request.params()[0]);
        auto five = static_cast<NumberLiteral &>(*subrequest.receiver());
        auto six = static_cast<NumberLiteral &>(*subrequest.params()[0]);

        REQUIRE_NOTHROW(request.identifier() == "+(_)");
        REQUIRE_NOTHROW(four.value() == 4);
        REQUIRE_NOTHROW(subrequest.identifier() == "*(_)");
        REQUIRE_NOTHROW(five.value() == 5);
        REQUIRE_NOTHROW(six.value() == 6);
    }

}

TEST_CASE("Primitives", "[Naylang Parser Visitor]") {
    SECTION("Parsing an integer creates a NumberLiteral") {
        StatementPtr AST = translate("4\n");
        REQUIRE_NOTHROW(dynamic_cast<NumberLiteral &>(*AST));
        REQUIRE_NOTHROW(dynamic_cast<NumberLiteral &>(*AST).value() == 4);
    }

    SECTION("Parsing a string in between quotes generates a StringLiteral") {
        StatementPtr AST = translate("\"Hello\"\n");
        REQUIRE_NOTHROW(dynamic_cast<StringLiteral &>(*AST).value() == "Hello");
    }

    SECTION("Parsing a boolean generates a BooleanLiteral") {
        StatementPtr AST = translate("true\n");
        REQUIRE_NOTHROW(dynamic_cast<BooleanLiteral &>(*AST).value());
    }
}

TEST_CASE("Values", "[Naylang Parser Visitor]") {
    SECTION("parsing \"object\" { /*some lines*/ } generates an ObjectConstructor node") {

    }
}

TEST_CASE("Declarations", "[Naylang Parser Visitor]") {
    SECTION("parsing 'def {name} = value' creates a ConstantDeclaration") {
        auto AST = translate("def x = 5");
        auto decl = static_cast<ConstantDeclaration &>(*AST);
        auto value = static_cast<NumberLiteral &>(*decl.value());
        REQUIRE_NOTHROW(static_cast<ConstantDeclaration &>(*AST));
        REQUIRE(decl.name() == "x");
        REQUIRE(value.value() == 5);
    }

    SECTION("parsing 'var {name} := value' creates a VariableDeclaration") {
        auto AST = translate("var x := 5");
        auto decl = static_cast<VariableDeclaration &>(*AST);
        auto value = static_cast<NumberLiteral &>(*decl.value());
        REQUIRE_NOTHROW(static_cast<VariableDeclaration &>(*AST));
        REQUIRE(decl.name() == "x");
        REQUIRE(value.value() == 5);
    }

    SECTION("Methods") {
        SECTION("Parsing 'method twice(n,m) { n * m }' creates a MethodDeclaration") {
            auto AST = translate("method twice(n,m) { n * m }");
            auto decl = static_cast<MethodDeclaration &>(*AST);
            auto inst = static_cast<ExplicitRequestNode &>(*decl.body()[0]);
            auto recv = static_cast<ImplicitRequestNode &>(*inst.receiver());
            auto param = static_cast<ImplicitRequestNode &>(*inst.params()[0]);
            REQUIRE(decl.name() == "twice(_,_)");
            REQUIRE(decl.params()[0]->name() == "n");
            REQUIRE(inst.identifier() == "*(_)");
            REQUIRE(recv.identifier() == "n");
            REQUIRE(param.identifier() == "m");
        }

        SECTION("Parsing 'method prefix!! { n * 2 }' creates a MethodDeclaration") {
            auto AST = translate("method prefix! { 2 * 2 }");
            auto decl = static_cast<MethodDeclaration &>(*AST);
            auto inst = static_cast<ExplicitRequestNode &>(*decl.body()[0]);
            auto recv = static_cast<NumberLiteral &>(*inst.receiver());
            auto param = static_cast<NumberLiteral &>(*inst.params()[0]);
            REQUIRE(decl.name() == "prefix!");
            REQUIRE(inst.identifier() == "*(_)");
            REQUIRE(recv.value() == 2);
            REQUIRE(param.value() == 2);
        }
    }
}

TEST_CASE("Requests", "[Naylang Parser Visitor]") {
    SECTION("Implicit Requests can be just an identifier") {
        auto AST = translate("x");
        auto req = static_cast<ImplicitRequestNode &>(*AST);
        REQUIRE(req.identifier() == "x");
        REQUIRE(req.params().size() == 0);
    }

    SECTION("Implicit Requests with one parameter can omit the parentheses") {
        auto AST = translate("print \"Hello\"");
        auto req = static_cast<ImplicitRequestNode &>(*AST);
        auto param = static_cast<StringLiteral &>(*req.params()[0]);
        REQUIRE(req.identifier() == "print(_)");
        REQUIRE(param.value() == "Hello");
    }

    SECTION("Implicit Requests with more than one parameter have to have them in parentheses") {
        auto AST = translate("twice(4, 5)");
        auto req = static_cast<ImplicitRequestNode &>(*AST);
        auto four = static_cast<NumberLiteral &>(*req.params()[0]);
        auto five = static_cast<NumberLiteral &>(*req.params()[1]);
        REQUIRE(req.identifier() == "twice(_,_)");
        REQUIRE(four.value() == 4);
        REQUIRE(five.value() == 5);
    }

    SECTION("Implicit Requests can have more than one part") {
        auto AST = translate("twice(4) as (5)");
        auto req = static_cast<ImplicitRequestNode &>(*AST);
        auto four = static_cast<NumberLiteral &>(*req.params()[0]);
        auto five = static_cast<NumberLiteral &>(*req.params()[1]);
        REQUIRE(req.identifier() == "twice(_)as(_)");
        REQUIRE(four.value() == 4);
        REQUIRE(five.value() == 5);
    }

    /*
    SECTION("Explicit Requests have a reciever") {
        auto AST = translate("x.say(5)");
        auto req = static_cast<ExplicitRequestNode &>(*AST);
        auto rec = static_cast<ImplicitRequestNode &>(*req.receiver());
        auto five = static_cast<NumberLiteral &>(*req.params()[0]);
        REQUIRE(req.identifier() == "say(_)");
        REQUIRE(rec.identifier() == "x");
        REQUIRE(five.value() == 5);
    }
     */
}

StatementPtr translate(std::string line) {
    ANTLRInputStream stream(line);
    GraceLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);
    GraceParser parser(&tokens);
    NaylangParserVisitor parserVisitor;

    auto program = parser.program();
    parserVisitor.visit(program);

    auto AST = parserVisitor.AST();
    return AST;
}
