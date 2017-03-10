//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/evaluators/BindingEvaluator.h>
#include "catch.h"
#include <model/ast/expressions/primitives/NumberLiteral.h>

using namespace naylang;

TEST_CASE("Binding Evaluator Tests", "[Evaluators]") {

    auto five = std::make_shared<NumberLiteral>(5);
    auto fiveBlock = std::make_shared<Block>(); fiveBlock->addStatement(five);

    auto xDecl = std::make_shared<VariableDeclaration>("x");
    auto methodDecl = std::make_shared<MethodDeclaration>("identifier", fiveBlock);
    auto constDecl = std::make_shared<ConstantDeclaration>("const", five);

    SECTION("A BindingEvaluator can return a symbol table with all declarations") {
        BindingEvaluator eval;
        REQUIRE(eval.symbolTable().size() == 0);
    }

    SECTION("Evaluating a Declaration inserts it into the symbol table") {
        BindingEvaluator eval;
        REQUIRE_NOTHROW(eval.evaluate(*xDecl););
        REQUIRE_NOTHROW(eval.evaluate(*methodDecl););
        REQUIRE_NOTHROW(eval.evaluate(*constDecl););

        REQUIRE(eval.symbolTable().at("x")->name() == xDecl->name());
        REQUIRE(eval.symbolTable().at("identifier")->name() == methodDecl->name());
        REQUIRE(eval.symbolTable().at("const")->name() == constDecl->name());
    }

    SECTION("Evaluating a VariableReference or Request throws if the symbol is not in the table") {
        BindingEvaluator eval;
        auto wrongVar = std::make_shared<VariableReference>("wrongVar");
        auto wrongMethod = std::make_shared<Request>("wrongMethod");
        REQUIRE_THROWS(eval.evaluate(*wrongVar));
        REQUIRE_THROWS(eval.evaluate(*wrongMethod));
    }

    SECTION("If a Request is evaluated after a MethodDeclaration with the same name, it binds to it") {
        BindingEvaluator eval;
        auto rightMethod = std::make_shared<Request>("identifier");

        eval.evaluate(*methodDecl);
        REQUIRE_NOTHROW(eval.evaluate(*rightMethod));

        REQUIRE(&rightMethod->declaration() == methodDecl.get());
    }

    SECTION("If a Request is evaluated after a MethodDeclaration with the same name, it binds to it") {
        BindingEvaluator eval;
        auto xVar = std::make_shared<VariableReference>("x");

        eval.evaluate(*xDecl);
        REQUIRE_NOTHROW(eval.evaluate(*xVar));

        REQUIRE(&xVar->declaration() == xDecl.get());
    }
}