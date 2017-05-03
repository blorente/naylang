//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <antlr4-runtime.h>
#include <GraceLexer.h>
#include <GraceParser.h>

#include <core/model/ast/ASTNodeDefinitions.h>
#include <core/model/ast/GraceAST.h>
#include <core/parser/NaylangParserVisitor.h>

using namespace naylang;
using namespace antlr4;

GraceAST translate(std::string line);

TEST_CASE("Program", "[Naylang Parser Visitor]") {
    SECTION("Parsing a program makes the AST to be a list of nodes") {
        GraceAST AST = translate("def x = \"Hello\";\ndef y = \"World\";");
        auto xDecl = static_cast<ConstantDeclaration &>(*(AST[0]));
        auto xVal = static_cast<StringLiteral &>(*xDecl.value());
        REQUIRE(xDecl.name() == "x");
        REQUIRE(xVal.value() == "Hello");

        auto yDecl = static_cast<ConstantDeclaration &>(*(AST[1]));
        auto yVal = static_cast<StringLiteral &>(*yDecl.value());
        REQUIRE(yDecl.name() == "y");
        REQUIRE(yVal.value() == "World");
    }
}

TEST_CASE("Naylang Parser Visitor", "[Parser]") {
    SECTION("Parsing -4 creates an explicit request 4.prefix-") {
        auto AST = translate("-4;\n");
        auto request = static_cast<ExplicitRequestNode &>(*(AST[0]));
        auto receiver = static_cast<NumberLiteral &>(*request.receiver());

        REQUIRE(request.identifier() == "prefix-");
        REQUIRE(receiver.value() == 4);
    }

    SECTION("Parsing 4 + 5 * 6 create the explicit request 4.+(5.*(6))") {
        auto AST = translate("4 + 5 * 6;\n");
        auto request = static_cast<ExplicitRequestNode &>(*(AST[0]));
        auto four = static_cast<NumberLiteral &>(*request.receiver());
        auto subrequest = static_cast<ExplicitRequestNode &>(*request.params()[0]);
        auto five = static_cast<NumberLiteral &>(*subrequest.receiver());
        auto six = static_cast<NumberLiteral &>(*subrequest.params()[0]);

        REQUIRE(request.identifier() == "+(_)");
        REQUIRE(four.value() == 4);
        REQUIRE(subrequest.identifier() == "*(_)");
        REQUIRE(five.value() == 5);
        REQUIRE(six.value() == 6);
    }

}

TEST_CASE("Primitives", "[Naylang Parser Visitor]") {
    SECTION("Parsing an integer creates a NumberLiteral") {
        auto AST = translate("4\n;");
        REQUIRE(dynamic_cast<NumberLiteral &>(*(AST[0])).value() == 4);
    }

    SECTION("Parsing a string in between quotes generates a StringLiteral") {
        auto AST = translate("\"Hello\";\n");
        REQUIRE(dynamic_cast<StringLiteral &>(*(AST[0])).value() == "Hello");
    }

    SECTION("Parsing a boolean generates a BooleanLiteral") {
        auto AST = translate("true;\n");
        REQUIRE(dynamic_cast<BooleanLiteral &>(*(AST[0])).value());
    }
}

TEST_CASE("Values", "[Naylang Parser Visitor]") {
    SECTION("Parsing \"object\" { /*some lines*/ } generates an ObjectConstructor node") {
        auto AST = translate("object {def x = 5;};");
        auto obj = static_cast<ObjectConstructor &>(*(AST[0]));
        auto decl = static_cast<ConstantDeclaration &>(*obj.statements()[0]);
        auto value = static_cast<NumberLiteral &>(*decl.value());
        REQUIRE(obj.statements().size() == 1);
        REQUIRE(decl.name() == "x");
        REQUIRE(value.value() == 5);
    }

    SECTION("Parsing a parameterless block creates a Block") {
        auto AST = translate("{def x = 5;};");
        auto obj = static_cast<Block &>(*(AST[0]));
        auto decl = static_cast<ConstantDeclaration &>(*obj.body()[0]);
        auto value = static_cast<NumberLiteral &>(*decl.value());
        REQUIRE(obj.body().size() == 1);
        REQUIRE(decl.name() == "x");
        REQUIRE(value.value() == 5);
    }

    SECTION("Parsing a block with parameter also creates a Block") {
        auto AST = translate("{x -> x * 5;};");
        auto obj = static_cast<Block &>(*(AST[0]));
        auto decl = static_cast<ExplicitRequestNode &>(*obj.body()[0]);
        auto param = static_cast<VariableDeclaration &>(*obj.params()[0]);
        auto x = static_cast<ImplicitRequestNode &>(*decl.receiver());
        auto value = static_cast<NumberLiteral &>(*decl.params()[0]);
        REQUIRE(param.name() == "x");
        REQUIRE(obj.body().size() == 1);
        REQUIRE(x.identifier() == "x");
        REQUIRE(value.value() == 5);
    }

    SECTION("Parsing [expr, expr, expr] creates a Lineup") {
        auto AST = translate("[{x -> x * 5;}, \"Hello\", 6];");

        auto lineup = static_cast<Lineup &>(*(AST[0]));

        auto block = static_cast<Block &>(*lineup.contents()[0]);
        auto decl = static_cast<ExplicitRequestNode &>(*block.body()[0]);
        auto param = static_cast<VariableDeclaration &>(*block.params()[0]);
        auto x = static_cast<ImplicitRequestNode &>(*decl.receiver());
        auto five = static_cast<NumberLiteral &>(*decl.params()[0]);
        REQUIRE(block.body().size() == 1);
        REQUIRE(param.name() == "x");
        REQUIRE(x.identifier() == "x");
        REQUIRE(five.value() == 5);

        auto hello = static_cast<StringLiteral &>(*lineup.contents()[1]);
        REQUIRE(hello.value() == "Hello");

        auto six = static_cast<NumberLiteral &>(*lineup.contents()[2]);
        REQUIRE(six.value() == 6);
    }

    SECTION("Parsing an object constructor") {
        GraceAST AST = translate("def obj = object {\nmethod add(n) to(t) {\nn + t;\n}\nvar val := 2;\n};");

        auto objDecl = static_cast<ConstantDeclaration &>(*(AST[0]));
        REQUIRE(objDecl.name() == "obj");
        auto objConst = static_cast<ObjectConstructor &>(*objDecl.value());
        REQUIRE(objConst.statements().size() == 2);

        auto methodDecl = static_cast<MethodDeclaration &>(*objConst.statements()[0]);
        REQUIRE(methodDecl.name() == "add(_)to(_)");
        auto nDecl = static_cast<VariableDeclaration &>(*methodDecl.params()[0]);
        REQUIRE(nDecl.name() == "n");
        auto tDecl = static_cast<VariableDeclaration &>(*methodDecl.params()[1]);
        REQUIRE(tDecl.name() == "t");
        auto body = static_cast<ExplicitRequestNode &>(*methodDecl.body()[0]);
        REQUIRE(body.identifier() == "+(_)");
        auto bodyRec = static_cast<ImplicitRequestNode &>(*body.receiver());
        REQUIRE(bodyRec.identifier() == "n");
        auto bodyParam = static_cast<ImplicitRequestNode &>(*body.params()[0]);
        REQUIRE(bodyParam.identifier() == "t");

        auto varDecl = static_cast<VariableDeclaration &>(*objConst.statements()[1]);
        REQUIRE(varDecl.name() == "val");
        auto value = static_cast<NumberLiteral &>(*varDecl.value());
        REQUIRE(value.value() == 2);
    }
}

TEST_CASE("Declarations", "[Naylang Parser Visitor]") {
    SECTION("parsing 'def {name} = value' creates a ConstantDeclaration") {
        auto AST = translate("def x = 5;");
        auto decl = static_cast<ConstantDeclaration &>(*(AST[0]));
        auto value = static_cast<NumberLiteral &>(*decl.value());
        REQUIRE(decl.name() == "x");
        REQUIRE(value.value() == 5);
    }

    SECTION("parsing 'var {name} := value' creates a VariableDeclaration") {
        auto AST = translate("var x := 5;");
        auto decl = static_cast<VariableDeclaration &>(*(AST[0]));
        auto value = static_cast<NumberLiteral &>(*decl.value());
        REQUIRE(decl.name() == "x");
        REQUIRE(value.value() == 5);
    }

    SECTION("Methods") {
        SECTION("Parsing 'method twice(n,m) { n * m }' creates a MethodDeclaration") {
            auto AST = translate("method twice(n,m) { n * m; }");
            auto decl = static_cast<MethodDeclaration &>(*(AST[0]));
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
            auto AST = translate("method prefix! { 2 * 2; }");
            auto decl = static_cast<MethodDeclaration &>(*(AST[0]));
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
        auto AST = translate("x;");
        auto req = static_cast<ImplicitRequestNode &>(*(AST[0]));
        REQUIRE(req.identifier() == "x");
        REQUIRE(req.params().size() == 0);
    }

    SECTION("Implicit Requests with one parameter can omit the parentheses") {
        auto AST = translate("print \"Hello\";");
        auto req = static_cast<ImplicitRequestNode &>(*(AST[0]));
        auto param = static_cast<StringLiteral &>(*req.params()[0]);
        REQUIRE(req.identifier() == "print(_)");
        REQUIRE(param.value() == "Hello");
    }

    SECTION("Implicit Requests with more than one parameter have to have them in parentheses") {
        auto AST = translate("twice(4, 5);");
        auto req = static_cast<ImplicitRequestNode &>(*(AST[0]));
        auto four = static_cast<NumberLiteral &>(*req.params()[0]);
        auto five = static_cast<NumberLiteral &>(*req.params()[1]);
        REQUIRE(req.identifier() == "twice(_,_)");
        REQUIRE(four.value() == 4);
        REQUIRE(five.value() == 5);
    }

    SECTION("Implicit Requests can have more than one part") {
        auto AST = translate("twice(4) as (5);");
        auto req = static_cast<ImplicitRequestNode &>(*(AST[0]));
        auto four = static_cast<NumberLiteral &>(*req.params()[0]);
        auto five = static_cast<NumberLiteral &>(*req.params()[1]);
        REQUIRE(req.identifier() == "twice(_)as(_)");
        REQUIRE(four.value() == 4);
        REQUIRE(five.value() == 5);
    }

    SECTION("Explicit Requests have a receiver") {
        auto AST = translate("x.say(5);");
        auto req = static_cast<ExplicitRequestNode &>(*(AST[0]));
        auto rec = static_cast<ImplicitRequestNode &>(*req.receiver());
        auto five = static_cast<NumberLiteral &>(*req.params()[0]);
        REQUIRE(req.identifier() == "say(_)");
        REQUIRE(rec.identifier() == "x");
        REQUIRE(five.value() == 5);
    }
}

TEST_CASE("Code Coordinates", "[Naylang Parser Visitor]") {
    SECTION("The visitor assigns code coordinates to every statement") {
        auto AST = translate("4;\n5;\nvar x := 4;\n");
        auto four = static_cast<NumberLiteral &>(*(AST[0]));
        REQUIRE(four.line() == 1);
        REQUIRE(four.col() == 0);
        auto five = static_cast<NumberLiteral &>(*(AST[1]));
        REQUIRE(five.line() == 2);
        REQUIRE(five.col() == 0);
        auto var = static_cast<VariableDeclaration &>(*(AST[2]));
        REQUIRE(var.line() == 3);
        REQUIRE(var.col() == 0);
    }
}

TEST_CASE("Stoppable nodes", "[Naylang Parser Visitor]") {
    SECTION("Variable Declarations are stoppable") {
        auto AST = translate("var x := 4;\n");
        auto x = static_cast<VariableDeclaration &>(*(AST[0]));
        REQUIRE(x.stoppable());
    }

    SECTION("Constant Declarations are stoppable") {
        auto AST = translate("def x = 4;\n");
        auto x = static_cast<ConstantDeclaration &>(*(AST[0]));
        REQUIRE(x.stoppable());
    }

    SECTION("Every line inside a MethodDeclaration is stoppable") {
        auto AST = translate("method twice(n,m) { var x := 4; x * m; }\n");
        auto meth = static_cast<MethodDeclaration &>(*(AST[0]));
        for (auto line : meth.body()) {
            REQUIRE(line->stoppable());
        }
    }

    SECTION("Every line inside a Prefix method is stoppable") {
        auto AST = translate("method prefix! { var x := 4; var m := -1; x * m; }\n");
        auto meth = static_cast<MethodDeclaration &>(*(AST[0]));
        for (auto line : meth.body()) {
            REQUIRE(line->stoppable());
        }
    }

    SECTION("Every line inside a Block is stoppable") {
        auto AST = translate("{ x, m -> var x := 4; x * m; };\n");
        auto block = static_cast<Block &>(*(AST[0]));
        for (auto line : block.body()) {
            REQUIRE(line->stoppable());
        }
    }
}

TEST_CASE("Assignment", "[Naylang Parser Visitor]") {
    SECTION("Assignments can have just an identifier") {
        auto AST = translate("x := 4;\n");
        auto assign = static_cast<Assignment &>(*(AST[0]));
        auto scope = static_cast<ImplicitRequestNode &>(*assign.scope());
        auto val = static_cast<NumberLiteral &>(*assign.value());
        REQUIRE(assign.field() == "x");
        REQUIRE(scope.identifier() == "self");
        REQUIRE(val.value() == 4.0);
    }

    SECTION("Assignments can a request and an identifier") {
        auto AST = translate("obj.x := 4;\n");
        auto assign = static_cast<Assignment &>(*(AST[0]));
        auto scope = static_cast<ImplicitRequestNode &>(*assign.scope());
        auto val = static_cast<NumberLiteral &>(*assign.value());
        REQUIRE(assign.field() == "x");
        REQUIRE(scope.identifier() == "obj");
        REQUIRE(val.value() == 4.0);
    }

    SECTION("Assignments can multiple requests and an identifier") {
        auto AST = translate("obj.val.x := 4;\n");
        auto assign = static_cast<Assignment &>(*(AST[0]));
        auto scope = static_cast<ExplicitRequestNode &>(*assign.scope());
        auto obj = static_cast<ImplicitRequestNode &>(*scope.receiver());
        auto val = static_cast<NumberLiteral &>(*assign.value());
        REQUIRE(assign.field() == "x");
        REQUIRE(scope.identifier() == "val");
        REQUIRE(obj.identifier() == "obj");
        REQUIRE(val.value() == 4.0);
    }
}

GraceAST translate(std::string line) {
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
