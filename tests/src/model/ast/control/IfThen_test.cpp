//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "catch.h"

#include <model/ast/control/IfThen.h>
#include <model/ast/expressions/Block.h>
#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/expressions/primitives/BooleanLiteral.h>

using namespace naylang;

TEST_CASE("If Then Expressions", "[Expressions]") {
    auto tru = std::make_shared<BooleanLiteral>(true);
    auto five = std::make_shared<NumberLiteral>(5.0);
    auto six = std::make_shared<NumberLiteral>(6.0);
    auto thenBlock = std::make_shared<Block>();
    thenBlock->addStatement(five);

    SECTION("IThen Expressions take a condition expression and a then block") {
        REQUIRE_NOTHROW(IfThen it(tru, thenBlock););
    }

    SECTION("ITE Expressions can return either of their fields") {
        IfThen it(tru, thenBlock);
        REQUIRE(it.condition() == tru);
        REQUIRE(it.thenExpression() == thenBlock);
    }
}