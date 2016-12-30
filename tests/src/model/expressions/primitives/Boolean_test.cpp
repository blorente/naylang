//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/expressions/primitives/Boolean.h"

using namespace naylang;

TEST_CASE("Boolean Expressions", "[Expressions]") {
    Boolean tru(true);
    Boolean otherTru(true);
    Boolean fals(false);

    SECTION("A Boolean can hold a bool") {
        REQUIRE(tru.value());
    }

    SECTION("A Boolean can test for equality with another Boolean") {
        REQUIRE(tru == otherTru);
        REQUIRE(!(fals == tru));
        REQUIRE(fals == fals);
    }
}