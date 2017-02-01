//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/expressions/primitives/Number.h>
#include <model/expressions/ExpressionBlock.h>

using namespace naylang;

TEST_CASE("Expression Blocks tests", "[Expressions]") {
    ExpressionBlock block;

    SECTION("An expression block is initially empty") {
        REQUIRE(block.expressions().size() == 0);
    }

    SECTION("Expressions can be added in FIFO order to a block") {
        auto five = std::make_shared<Number>(5.0);
        auto six = std::make_shared<Number>(6.0);
        block.addExpression(five);
        block.addExpression(six);

        REQUIRE(static_cast<const Number&>(*(block.expressions()[0])).value() == 5.0);
        REQUIRE(static_cast<const Number&>(*(block.expressions()[1])).value() == 6.0);
    }
}
