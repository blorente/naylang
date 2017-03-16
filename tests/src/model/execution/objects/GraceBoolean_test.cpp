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

    SECTION("A GraceBoolean can dispatch the prefix! method as predefined") {
        ExecutionEvaluator eval;
        bul.dispatch("prefix!", eval);
    }

    SECTION("GraceTrue and GraceFalse constants are predefined") {
        REQUIRE(GraceTrue->value());
        REQUIRE(!GraceFalse->value());
    }
}

TEST_CASE("Predefined methods in GraceBoolean", "[GraceBoolean]") {
    ExecutionEvaluator eval;

    SECTION("PrefixNot") {
        GraceBoolean::PrefixNot method;

        SECTION("Calling PrefixNot with self == GraceTrue returns GraceFalse") {
            GraceObjectPtr val = method.respond(eval, *GraceTrue);
            REQUIRE(*GraceFalse == *val);
        }

        SECTION("Calling PrefixNot with self == GraceFalse returns GraceTrue") {
            GraceObjectPtr val = method.respond(eval, *GraceFalse);
            REQUIRE(*GraceTrue == *val);
        }
    }
}