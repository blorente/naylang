//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/statements/Constant.h"
#include "model/expressions/primitives/Number.h"

using namespace naylang;

TEST_CASE("Constant Expressions", "[Expressions]") {
    SECTION("A constant can hold a Number") {
        auto five = std::make_shared<Number>(5.0);
        auto name = "x";
        Constant c(name, five);

        REQUIRE(c.identifier() == "x");
        REQUIRE(static_cast<Number &>(*c.value()) == *five);
    }
}