//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/environment/GraceObject.h>

using namespace naylang;

TEST_CASE("Grace Object", "[Environment]") {
    GraceObject numFive(5.0);
    GraceObject otherFive(5.0);
    GraceObject numSix(6.0);

    SECTION("Grace objects can be initialized with numbers") {
        GraceObject zero(0.0);
    }

    SECTION("Grace number objects are equal iff their numbers are the same") {
        REQUIRE(numFive == otherFive);
        REQUIRE(numSix != numFive);
    }
}