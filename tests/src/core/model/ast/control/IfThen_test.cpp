//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "catch.h"

#include <core/model/ast/control/IfThen.h>
#include <core/model/ast/expressions/Block.h>
#include <core/model/ast/expressions/primitives/NumberLiteral.h>
#include <core/model/ast/expressions/primitives/BooleanLiteral.h>
#include <core/model/ast/NodeFactory.h>

using namespace naylang;

TEST_CASE("If Then Expressions", "[Control]") {
    auto tru = make_node<BooleanLiteral>(true);
    auto five = make_node<NumberLiteral>(5.0);
    auto six = make_node<NumberLiteral>(6.0);
    std::vector<StatementPtr> thenBlock{five};

    SECTION("IThen Expressions take a condition expression and a then block") {
        REQUIRE_NOTHROW(IfThen it(tru, thenBlock););
    }

    SECTION("ITE Expressions can return either of their fields") {
        IfThen it(tru, thenBlock);
        REQUIRE(it.condition() == tru);
        REQUIRE(it.thenPart() == thenBlock);
    }
}