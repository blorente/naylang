//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/expressions/VariableReference.h"

using namespace naylang;

TEST_CASE("VariableReference Expressions", "[Expressions]") {
    SECTION("A variable reference just needs an canonName") {
        auto name = "y";
        VariableReference refenenceY(name);

        REQUIRE(refenenceY.identifier() == "y");
    }
}
