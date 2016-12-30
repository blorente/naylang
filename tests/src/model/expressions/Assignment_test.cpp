//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/expressions/Assignment.h"
#include "model/expressions/Number.h"

using namespace naylang;

TEST_CASE("Assignment Expressions", "[Expressions]") {
    SECTION("Assignment Expressions can hold an identifier and a value") {
        auto five = std::make_shared<Number>(5.0);
        auto name = "y";
        Assignment numberAssignment(name, five);

        REQUIRE(numberAssignment.identifier() == "y");
        REQUIRE(static_cast<Number &>(*numberAssignment.value()) == *five);
    }
}
