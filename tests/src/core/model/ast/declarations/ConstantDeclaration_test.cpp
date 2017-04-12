//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/ast/declarations/ConstantDeclaration.h>
#include <core/model/ast/expressions/primitives/NumberLiteral.h>
#include <core/model/ast/NodeFactory.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Constant Declaration Statements", "[Declarations]") {
    auto name = "x";
    auto five = make_node<NumberLiteral>(5.0);

    SECTION("A constant declaration needs a name and a value (Expression)") {
        ConstantDeclaration constX(name, five);
    }

    SECTION("A constant declaration can return it's name and value") {
        ConstantDeclaration constX(name, five);
        REQUIRE(constX.name() == "x");
        REQUIRE(constX.value() == five);
    }
}




