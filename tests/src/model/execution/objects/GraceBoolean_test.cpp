//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/execution/objects/GraceBoolean.h>
#include <model/evaluators/ExecutionEvaluator.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Grace Boolean", "[GraceObjects]") {
    GraceBoolean bul(true);

    SECTION("A GraceBoolean can return it's raw boolean value") {
        REQUIRE(bul.value());
    }

    SECTION("A GraceBoolean can dispatch the !() method as predefined") {
        ExecutionEvaluator eval;
        bul.dispatch("prefix!", eval);
    }
}