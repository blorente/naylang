//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/ast/expressions/primitives/NumberLiteral.h"

using namespace naylang;

TEST_CASE("Number Literal Expressions", "[Expressions]") {
    SECTION("A NumberLiteral can hold a double") {
        NumberLiteral five(5.0);
        REQUIRE(five.value() == 5.0);
    }

    SECTION("A NumberLiteral can test for equality with another number") {
        NumberLiteral five(5.0);
        NumberLiteral two(2.0);
        NumberLiteral minusOne(-1.0);
        NumberLiteral otherFive(5.0);

        REQUIRE(five == otherFive);
        REQUIRE(!(five == two));
        REQUIRE(!(five == minusOne));
    }
}