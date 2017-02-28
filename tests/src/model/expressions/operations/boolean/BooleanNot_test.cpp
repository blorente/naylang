//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "catch.h"

#include "model/expressions/operations/boolean/BooleanNot.h"
#include "model/expressions/primitives/Boolean.h"

using namespace naylang;

TEST_CASE("Boolean Not Expressions", "[Expressions]") {
    auto tru = std::make_shared<Boolean>(true);
    auto fals = std::make_shared<Boolean>(false);

    SECTION("A boolean Not accepts two expressions as parameters") {
        REQUIRE_NOTHROW(BooleanNot notTrue(tru););
        REQUIRE_NOTHROW(BooleanNot notFalse(fals););
    }

    SECTION("A boolean Not can return it's operands") {
        BooleanNot notTrue(tru);
        REQUIRE(static_cast<Boolean*>(notTrue.operand().get())->value());
    }
}