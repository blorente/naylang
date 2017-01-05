//
// Copyright (c) 1/5/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/expressions/methods/MethodDeclaration.h>
#include <model/expressions/primitives/Number.h>

using namespace naylang;

TEST_CASE("Methd Declarations", "[Expressions]") {
    Identifier name("myMethod");
    auto five = std::make_shared<Number>(5.0);

    SECTION("A method delaration takes an identifier and a body expression") {
        MethodDeclaration method(name, five);
    }

    SECTION("A method declaration returns it's name and body") {
        MethodDeclaration method(name, five);

        REQUIRE(method.getCanonName().identifier() == "myMethod");
        REQUIRE(static_cast<Number &>(*(method.getBody())).value() == 5.0);
    }
}