//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/ast/expressions/primitives/StringLiteral.h"

using namespace naylang;

TEST_CASE("String Literal Expressions", "[Expressions]") {
    StringLiteral hello("hello");
    StringLiteral otherHello("hello");
    StringLiteral bye("bye");

    SECTION("A String Literal can hold an std::string") {
        REQUIRE(hello.value() == "hello");
    }

    SECTION("A String Literal can test for equality with another String Literal") {
        REQUIRE(hello == otherHello);
        REQUIRE(hello != bye);
    }
}



