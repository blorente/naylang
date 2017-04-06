//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/evaluators/BindingEvaluator.h>
#include "catch.h"

#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/NodeFactory.h>

using namespace naylang;

TEST_CASE("Binding Evaluator Tests", "[Evaluators]") {

    auto five = make_node<NumberLiteral>(5.0);
    std::vector<DeclarationPtr> identifierParams{};
    std::vector<StatementPtr> identifierBody{};

    auto xDecl = make_node<VariableDeclaration>("x");
    auto methodDecl = make_node<MethodDeclaration>("identifier", identifierParams, identifierBody);
    auto constDecl = make_node<ConstantDeclaration>("const", five);

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

    SECTION("Evaluating a VariableReference or RequestNode throws if the symbol is not in the table") {
        BindingEvaluator eval;
        auto wrongVar = make_node<ImplicitRequestNode>("wrongVar");
        auto wrongMethod = make_node<ImplicitRequestNode>("wrongMethod");
        REQUIRE_THROWS(eval.evaluate(*wrongVar));
        REQUIRE_THROWS(eval.evaluate(*wrongMethod));
    }

    SECTION("If a RequestNode is evaluated after a MethodDeclaration with the same name, it binds to it") {
        BindingEvaluator eval;
        auto rightMethod = make_node<ExplicitRequestNode>("identifier", five);

        eval.evaluate(*methodDecl);
        REQUIRE_NOTHROW(eval.evaluate(*rightMethod));

        REQUIRE(rightMethod->declaration() == methodDecl.get());
    }

    SECTION("If a RequestNode is evaluated after a MethodDeclaration with the same name, it binds to it") {
        BindingEvaluator eval;
        auto xVar = make_node<ImplicitRequestNode>("x");

        eval.evaluate(*xDecl);
        REQUIRE_NOTHROW(eval.evaluate(*xVar));

        REQUIRE(xVar->declaration() == xDecl.get());
    }
}