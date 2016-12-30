//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "catch.h"

#include "model/expressions/operations/Multiplication.h"
#include "model/expressions/primitives/Number.h"

using namespace naylang;

TEST_CASE("Multiplication Expressions", "[Expressions]") {
    auto five = std::make_shared<Number>(5.0);
    auto six = std::make_shared<Number>(6.0);

    SECTION("A multiplication accepts two expressions as parameters") {
        Multiplication eleven(five, six);
    }

    SECTION("A multiplication can return it's operands") {
        Multiplication eleven(five, six);
        REQUIRE(static_cast<Number*>(eleven.leftOperand().get())->value() == 5.0);
        REQUIRE(static_cast<Number*>(eleven.rightOperand().get())->value() == 6.0);
    }
}

