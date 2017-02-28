//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/statements/VariableDeclaration.h"

using namespace naylang;

TEST_CASE("VariableDeclaration Expressions", "[Expressions]") {
    SECTION("A variable declaration just needs an canonName") {
        auto name = "y";
        VariableDeclaration declareY(name);

        REQUIRE(declareY.identifier() == "y");
    }
}
