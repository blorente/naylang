//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/ast/control/While.h>
#include <model/ast/expressions/Block.h>
#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/expressions/primitives/BooleanLiteral.h>
#include <model/ast/NodeFactory.h>

using namespace naylang;

TEST_CASE("While Loop", "[Control]") {

    auto tru = make_node<BooleanLiteral>(true);
    auto truBlock = make_node<Block>();
    truBlock->addStatement(tru);

    auto five = make_node<NumberLiteral>(5.0);
    auto fiveBlock = make_node<Block>();
    fiveBlock->addStatement(five);

    SECTION("A while loop accepts a condition block and a body block") {
        REQUIRE_NOTHROW(While loop(truBlock, fiveBlock););
    }

    SECTION("A while loop can return it's condition and body") {
        While loop(truBlock, fiveBlock);
        REQUIRE(loop.condition() == truBlock);
        REQUIRE(loop.body() == fiveBlock);
    }
}




