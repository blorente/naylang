//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "catch.h"

#include <model/ast/control/IfThenElse.h>
#include <model/ast/expressions/Block.h>
#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/expressions/primitives/BooleanLiteral.h>

using namespace naylang;

TEST_CASE("If Then Else Expressions", "[Expressions]") {
    auto tru = std::make_shared<BooleanLiteral>(true);
    auto five = std::make_shared<NumberLiteral>(5.0);
    auto six = std::make_shared<NumberLiteral>(6.0);
    auto thenBlock = std::make_shared<Block>();
    thenBlock->addStatement(five);
    auto elseBlock = std::make_shared<Block>();
    elseBlock->addStatement(six);

    SECTION("ITE Expressions take a condition expression and two consequence blocks") {
        REQUIRE_NOTHROW(IfThenElse ite(tru, thenBlock, elseBlock););
    }

    SECTION("ITE Expressions can return either of their fields") {
        IfThenElse ite(tru, thenBlock, elseBlock);
        REQUIRE(ite.condition() == tru);
        REQUIRE(ite.thenExpression() == thenBlock);
        REQUIRE(ite.elseExpression() == elseBlock);
    }
}