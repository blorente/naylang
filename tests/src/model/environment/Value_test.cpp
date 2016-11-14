//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/environment/Value.h"

using namespace naylang;

TEST_CASE("Value", "[Environment]") {
    SECTION("A Value can only hold a double") {
        Value five(5.0);
        REQUIRE(five.value() == 5.0);
    }

    SECTION("Two Values are equal iff their doubles are equal") {
        Value five(5.0);
        Value anotherFive(5.0);
        Value one(1.0);
        REQUIRE(five == anotherFive);
        REQUIRE(!(five == one));
    }
}