//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/ast/declarations/VariableDeclaration.h>
#include <model/ast/NodeFactory.h>
#include "catch.h"


using namespace naylang;

TEST_CASE("VariableDeclaration Statements", "[Declarations]") {
    SECTION("A variable declaration just needs a name") {
        auto name = "y";
        VariableDeclaration declareY(name);

        REQUIRE(declareY.name() == "y");
    }

    SECTION("A variable declaration can also contain an initial value") {
        auto name = "y";
        auto five = make_node<NumberLiteral>(5);
        VariableDeclaration declareY(name, five);

        REQUIRE(declareY.name() == "y");
        REQUIRE(declareY.value() == five);
    }
}
