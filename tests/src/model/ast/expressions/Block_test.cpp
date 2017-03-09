//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/declarations/VariableDeclaration.h>
#include "catch.h"

#include "model/ast/expressions/Block.h"

using namespace naylang;

TEST_CASE("Block Expressions", "[Expressions]") {

    SECTION("A block can retrieve it's body, which is a vector of Statements") {
        Block b;
        REQUIRE(b.body().size() == 0);
    }

    SECTION("A block can retrieve it's parameters, which is a vector of Declarations") {
        Block b;
        REQUIRE(b.params().size() == 0);
    }

    SECTION("A statement can be added to the block body") {
        Block b;
        auto one = std::make_shared<NumberLiteral>(1);
        b.addStatement(one);
        REQUIRE(b.body().size() == 1);
    }

    SECTION("A parameter can be added to the block parameters") {
        Block b;
        auto x = std::make_shared<VariableDeclaration>("x");
        b.addParameter(x);
        REQUIRE(b.params().size() == 1);
    }
}



