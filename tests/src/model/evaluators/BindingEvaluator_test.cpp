//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/evaluators/BindingEvaluator.h>
#include "catch.h"
#include <model/ast/declarations/ConstantDeclaration.h>
#include <model/ast/declarations/VariableDeclaration.h>
#include <model/ast/declarations/MethodDeclaration.h>
#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/expressions/Block.h>

using namespace naylang;

TEST_CASE("Binding Evaluator Tests", "[Evaluators]") {

    auto five = std::make_shared<NumberLiteral>(5);
    auto fiveBlock = std::make_shared<Block>(); fiveBlock->addStatement(five);

    auto xDecl = std::make_shared<VariableDeclaration>("x");
    auto methodDecl = std::make_shared<MethodDeclaration>("method", fiveBlock);
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

        REQUIRE(eval.symbolTable().at("x") == xDecl);
        REQUIRE(eval.symbolTable().at("method") == methodDecl);
        REQUIRE(eval.symbolTable().at("const") == constDecl);
    }
}