//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "catch.h"

#include <core/model/ast/control/IfThenElse.h>
#include <core/model/ast/expressions/Block.h>
#include <core/model/ast/expressions/primitives/NumberLiteral.h>
#include <core/model/ast/expressions/primitives/BooleanLiteral.h>
#include <core/model/ast/NodeFactory.h>

using namespace naylang;

TEST_CASE("If Then Else Expressions", "[Control]") {
    auto tru = make_node<BooleanLiteral>(true);
    auto five = make_node<NumberLiteral>(5.0);
    auto six = make_node<NumberLiteral>(6.0);
    std::vector<StatementPtr> thenBlock{five};
    std::vector<StatementPtr> elseBlock{six};

    SECTION("ITE Expressions take a condition expression and two consequence blocks") {
        REQUIRE_NOTHROW(IfThenElse ite(tru, thenBlock, elseBlock););
    }

    SECTION("ITE Expressions can return either of their fields") {
        IfThenElse ite(tru, thenBlock, elseBlock);
        REQUIRE(ite.condition() == tru);
        REQUIRE(ite.thenPart() == thenBlock);
        REQUIRE(ite.elsePart() == elseBlock);
    }
}