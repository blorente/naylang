//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/ast/expressions/primitives/BooleanLiteral.h"

using namespace naylang;

TEST_CASE("Boolean Literal Expressions", "[Expressions]") {
    BooleanLiteral tru(true);
    BooleanLiteral otherTru(true);
    BooleanLiteral fals(false);

    SECTION("A BooleanLiteral can hold a bool") {
        REQUIRE(tru.value());
    }

    SECTION("A BooleanLiteral can test for equality with another BooleanLiteral") {
        REQUIRE(tru == otherTru);
        REQUIRE(!(fals == tru));
        REQUIRE(fals == fals);
    }
}