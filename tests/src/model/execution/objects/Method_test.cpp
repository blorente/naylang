//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/execution/objects/Method.h>
#include <model/ast/expressions/Block.h>
#include <model/ast/NodeFactory.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Method", "[GraceObjects]") {

    auto fiveBlock = make_node<Block>();
    SECTION("A method takes a Block") {
        REQUIRE_NOTHROW(Method meth(fiveBlock););
    }

    SECTION("A method can return it's code") {
        Method meth(fiveBlock);
        REQUIRE(meth.code() == fiveBlock);
    }
}