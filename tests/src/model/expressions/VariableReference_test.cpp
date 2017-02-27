//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/expressions/VariableReference.h"
#include <model/statements/VariableDeclaration.h>

using namespace naylang;

TEST_CASE("VariableReference Expressions", "[Expressions]") {
    SECTION("A Variable Reference must be linked to a declaration") {
        auto name = std::make_shared<VariableDeclaration>("y");
        VariableReference referenceY(name);

        REQUIRE(referenceY.identifier() == "y");
    }
}
