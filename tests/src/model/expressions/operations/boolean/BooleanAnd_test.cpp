//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "catch.h"

#include "model/expressions/operations/boolean/BooleanAnd.h"
#include "model/expressions/primitives/Boolean.h"

using namespace naylang;

TEST_CASE("Boolean And Expressions", "[Expressions]") {
    auto tru = std::make_shared<Boolean>(true);
    auto fals = std::make_shared<Boolean>(false);

    SECTION("A boolean and accepts two expressions as parameters") {
        REQUIRE_NOTHROW(BooleanAnd trueAndFalse(tru, fals););
    }

    SECTION("A boolean and can return it's operands") {
        BooleanAnd trueAndFalse(tru, fals);
        REQUIRE(static_cast<Boolean*>(trueAndFalse.leftOperand().get())->value());
        REQUIRE(!static_cast<Boolean*>(trueAndFalse.rightOperand().get())->value());
    }
}
