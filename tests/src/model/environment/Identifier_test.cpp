//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/environment/Identifier.h>

using namespace naylang;

TEST_CASE("Identifier", "[Environment]") {
    Identifier one("x");
    Identifier other("y");
    Identifier anotherOne("x");
    std::vector<std::string> words {"Hello", "World", "Identifier"};

    SECTION("An identifier can be initialized with a naked string") {
        Identifier stringIdentifier("hi");
    }

    SECTION("An identifier can be initialized with a vector of strings") {
        Identifier vectorIdentifier(words);
    }

    SECTION("The string representation is achieved by inserting (__) between words") {
        Identifier stringIdentifier("Hello");
        Identifier vectorIdentifier(words);
        REQUIRE(stringIdentifier.identifier() == "Hello");
        REQUIRE(vectorIdentifier.identifier() == "Hello(__)World(__)Identifier");
    }

    SECTION("Two identifiers are == iff their string representations are the same") {
        Identifier stringIdentifier("Hello(__)World(__)Identifier");
        Identifier vectorIdentifier(words);
        REQUIRE(one == anotherOne);
        REQUIRE(one != other);
        REQUIRE(other == other);

        REQUIRE(stringIdentifier == vectorIdentifier);
    }

}