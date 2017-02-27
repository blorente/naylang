//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/statements/control/WhileLoop.h>
#include <model/expressions/primitives/Number.h>
#include <model/expressions/primitives/Boolean.h>

using namespace naylang;

TEST_CASE("While Loop", "[Statements]") {

    auto tru = std::make_shared<Boolean>(true);
    auto five = std::make_shared<Number>(5.0);
    auto fiveBlock = std::make_shared<ExpressionBlock>();
    fiveBlock->addInstruction(five);

    SECTION("A while loop accepts a condition expression and a body (block)") {
        REQUIRE_NOTHROW(WhileLoop loop(tru, fiveBlock););
    }

    SECTION("A while loop can return it's condition and body") {
        WhileLoop loop(tru, fiveBlock);
        REQUIRE(loop.condition() == tru);
        REQUIRE(loop.body() == fiveBlock);
    }
}




