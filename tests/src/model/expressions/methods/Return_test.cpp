//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/expressions/methods/Return.h>
#include <model/expressions/primitives/Number.h>

using namespace naylang;

TEST_CASE("Return Expressions", "[Expressions]") {
    auto five = std::make_shared<Number>(5.0);

    SECTION("Return expressions hold an expression") {
        REQUIRE_NOTHROW(Return ret(five););
    }

    SECTION("Return expressions can return their expressions") {
        Return ret(five);
        REQUIRE(ret.expression() == five);
    }
}



