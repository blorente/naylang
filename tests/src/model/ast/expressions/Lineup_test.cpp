//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/ast/expressions/Lineup.h>
#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/NodeFactory.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Lineups", "[Expressions]") {

    auto five = make_node<NumberLiteral>(5.0);
    auto six = make_node<NumberLiteral>(6.0);
    auto fiveSix = {five, six};

    SECTION("A Lineup accepts an expression list") {
        Lineup l({five, six});
    }

    SECTION("A Lineup can return a list of it's expressions") {
        Lineup l({five, six});
        REQUIRE(std::equal(l.contents().begin(), l.contents().end(), fiveSix.begin()));
    }
}