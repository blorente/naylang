//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"
#include <model/environment/identifiers/Identifier.h>
#include <model/environment/identifiers/VariableIdentifier.h>
#include <model/environment/identifiers/MethodIdentifier.h>

using namespace naylang;

TEST_CASE("Identifier", "[Environment]") {
    VariableIdentifier one("x");
    VariableIdentifier other("y");
    VariableIdentifier anotherOne("x");

    SECTION("Two identifiers are == iff their canonical names are the same") {
        VariableIdentifier stringIdentifier = VariableIdentifier("var1");
        VariableIdentifier vectorIdentifier = VariableIdentifier("var1");
        REQUIRE(one == anotherOne);
        REQUIRE(one != other);
        REQUIRE(other == other);

        REQUIRE(stringIdentifier == vectorIdentifier);
    }
    
    SECTION("Method identifiers can be compared with Variable identifiers") {
        MethodIdentifier different("Hello", 0);
        MethodIdentifier same("x", 0);

        REQUIRE(one == same);
        REQUIRE(one != different);
    }
}



