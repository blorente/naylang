//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "catch.h"

#include <model/statements/IfThenElse.h>
#include <model/expressions/primitives/Number.h>
#include <model/expressions/operations/Subtraction.h>

using namespace naylang;

TEST_CASE("If Then Else Expressions", "[Expressions]") {
    auto tru = std::make_shared<Boolean>(true);
    auto five = std::make_shared<Number>(5.0);
    auto six = std::make_shared<Number>(6.0);
    auto toOne = std::make_shared<Subtraction>(six, five);

    SECTION("ITE Expressions take a condition expression and two consequence expressions") {
        IfThenElse ite(tru, five, toOne);
    }
}