//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/ast/expressions/ObjectConstructor.h>
#include <core/model/ast/expressions/primitives/NumberLiteral.h>
#include <core/model/ast/NodeFactory.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Object Constructor Expressions", "[Expressions]") {
    auto five = make_node<NumberLiteral>(5.0);
    auto six = make_node<NumberLiteral>(6.0);
    std::vector<StatementPtr> fiveSix = {five, six};

    SECTION("An object constructor just contains a set of statements") {
        ObjectConstructor obj(fiveSix);
        REQUIRE(std::equal(fiveSix.begin(), fiveSix.end(), obj.statements().begin()));
    }
}