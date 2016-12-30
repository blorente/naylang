//
// Created by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "catch.h"

#include "model/expressions/operations/Division.h"
#include "model/expressions/Number.h"

using namespace naylang;

TEST_CASE("Division Expressions", "[Expressions]") {
    auto five = std::make_shared<Number>(5.0);
    auto six = std::make_shared<Number>(6.0);

    SECTION("A division accepts two expressions as numerator and denominator") {
        Division eleven(five, six);
    }

    SECTION("A division can return it's operands") {
        Division eleven(five, six);
        REQUIRE(static_cast<Number*>(eleven.numerator().get())->value() == 5.0);
        REQUIRE(static_cast<Number*>(eleven.denominator().get())->value() == 6.0);
    }
}
