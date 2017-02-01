//
// Created by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "catch.h"

#include "model/expressions/operations/Subtraction.h"
#include "model/expressions/primitives/Number.h"

using namespace naylang;

TEST_CASE("Subtraction Expressions", "[Expressions]") {
    auto five = std::make_shared<Number>(5.0);
    auto six = std::make_shared<Number>(6.0);

    SECTION("A subtraction accepts two expressions as parameters") {
        Subtraction eleven(five, six);
    }

    SECTION("A subtraction can return it's operands") {
        Subtraction eleven(five, six);
        REQUIRE(static_cast<Number*>(eleven.leftOperand().get())->value() == 5.0);
        REQUIRE(static_cast<Number*>(eleven.rightOperand().get())->value() == 6.0);
    }
}
