//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "catch.h"

#include <model/expressions/operations/boolean/BooleanOr.h>
#include <model/expressions/primitives/Boolean.h>

using namespace naylang;

TEST_CASE("Boolean Or Expressions", "[Expressions]") {
    auto tru = std::make_shared<Boolean>(true);
    auto fals = std::make_shared<Boolean>(false);

    SECTION("A boolean Or accepts two expressions as parameters") {
        REQUIRE_NOTHROW(BooleanOr trueOrFalse(tru, fals););
    }

    SECTION("A boolean Or can return it's operands") {
        BooleanOr trueOrFalse(tru, fals);
        REQUIRE(static_cast<Boolean*>(trueOrFalse.leftOperand().get())->value());
        REQUIRE(!static_cast<Boolean*>(trueOrFalse.rightOperand().get())->value());
    }
}




