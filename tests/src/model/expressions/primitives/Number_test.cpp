//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/expressions/primitives/Number.h"

using namespace naylang;

TEST_CASE("Number Expressions", "[Expressions]") {
    SECTION("A Number can hold a double") {
        Number five(5.0);
        REQUIRE(five.value() == 5.0);
    }

    SECTION("A Number can test for equality with another number") {
        Number five(5.0);
        Number two(2.0);
        Number minusOne(-1.0);
        Number otherFive(5.0);

        REQUIRE(five == otherFive);
        REQUIRE(!(five == two));
        REQUIRE(!(five == minusOne));
    }
}