//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/statements/Assignment.h"
#include "model/expressions/primitives/Number.h"

using namespace naylang;

TEST_CASE("Assignment Expressions", "[Expressions]") {
    SECTION("Assignment Expressions can hold an canonName and a asNumber") {
        auto five = std::make_shared<Number>(5.0);
        auto name = "y";
        Assignment numberAssignment(name, five);

        REQUIRE(numberAssignment.identifier() == "y");
        REQUIRE(static_cast<Number &>(*numberAssignment.value()) == *five);
    }
}
