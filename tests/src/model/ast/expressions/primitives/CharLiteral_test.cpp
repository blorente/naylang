//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/ast/expressions/primitives/CharLiteral.h"

using namespace naylang;

TEST_CASE("Char Literal Expressions", "[Expressions]") {
    CharLiteral a('a');
    CharLiteral otherA('a');
    CharLiteral b('b');
    CharLiteral c('c');

    SECTION("A CharLiteral can hold a char") {
        REQUIRE(a.value() == 'a');
    }

    SECTION("A CharLiteral can test for equality with another CharLiteral") {
        REQUIRE(a == otherA);
        REQUIRE(!(a == b));
        REQUIRE(b == b);
    }
}

