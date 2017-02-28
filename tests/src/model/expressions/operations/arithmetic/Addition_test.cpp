//
// Created by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/expressions/operations/arithmetic/Addition.h"
#include "model/expressions/primitives/Number.h"

using namespace naylang;

TEST_CASE("Addition Expressions", "[Expressions]") {
    auto five = std::make_shared<Number>(5.0);
    auto six = std::make_shared<Number>(6.0);

    SECTION("An addition accepts two expressions as parameters") {
        Addition eleven(five, six);
    }

    SECTION("An addition can return it's operands") {
        Addition eleven(five, six);
        REQUIRE(static_cast<Number*>(eleven.leftOperand().get())->value() == 5.0);
        REQUIRE(static_cast<Number*>(eleven.rightOperand().get())->value() == 6.0);
    }
}
