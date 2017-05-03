//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <core/model/ast/control/While.h>
#include <core/model/ast/expressions/primitives/NumberLiteral.h>
#include <core/model/ast/expressions/primitives/BooleanLiteral.h>
#include <core/model/ast/NodeFactory.h>

using namespace naylang;

TEST_CASE("While Loop", "[Control]") {

    auto tru = make_node<BooleanLiteral>(true);

    auto five = make_node<NumberLiteral>(5.0);
    std::vector<StatementPtr> fiveBlock{five};

    SECTION("A while loop accepts a condition block and a body block") {
        REQUIRE_NOTHROW(While loop(tru, fiveBlock););
    }

    SECTION("A while loop can return it's condition and body") {
        While loop(tru, fiveBlock);
        REQUIRE(loop.condition() == tru);
        REQUIRE(loop.body() == fiveBlock);
    }
}




