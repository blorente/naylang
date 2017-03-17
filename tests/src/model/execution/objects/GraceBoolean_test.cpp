//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/execution/objects/GraceBoolean.h>
#include <model/ast/expressions/primitives/BooleanLiteral.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Grace Boolean", "[GraceObjects]") {
    GraceBoolean bul(true);

    SECTION("A GraceBoolean can return it's raw boolean value") {
        REQUIRE(bul.value());
    }

    SECTION("A GraceBoolean can dispatch the prefix! and &&(_) methods as predefined") {
        ExecutionEvaluator eval;
        REQUIRE(*GraceFalse == *bul.dispatch("prefix!", eval));
        eval.evaluate(*make_node<BooleanLiteral>(true));
        REQUIRE(*GraceTrue == *bul.dispatch("&&(_)", eval));
    }

    SECTION("GraceTrue and GraceFalse constants are predefined") {
        REQUIRE(GraceTrue->value());
        REQUIRE(!GraceFalse->value());
    }
}

TEST_CASE("Predefined methods in GraceBoolean", "[GraceBoolean]") {
    SECTION("PrefixNot") {
        MethodRequest req("prefix!");
        GraceBoolean::PrefixNot method;

        SECTION("Calling PrefixNot with self == GraceTrue returns GraceFalse") {
            GraceObjectPtr val = method.respond(*GraceTrue, req);
            REQUIRE(*GraceFalse == *val);
        }

        SECTION("Calling PrefixNot with self == GraceFalse returns GraceTrue") {
            GraceObjectPtr val = method.respond(*GraceFalse, req);
            REQUIRE(*GraceTrue == *val);
        }
    }

    SECTION("AndAnd") {
        MethodRequest andTrue("&&(_)", {GraceTrue});
        MethodRequest andFalse("&&(_)", {GraceFalse});
        GraceBoolean::AndAnd method;

        SECTION("AndAnd returns true iff self && req.params()[0]") {
            REQUIRE(*GraceTrue == *method.respond(*GraceTrue, andTrue));
            REQUIRE(*GraceFalse == *method.respond(*GraceTrue, andFalse));
            REQUIRE(*GraceFalse == *method.respond(*GraceFalse, andTrue));
            REQUIRE(*GraceFalse == *method.respond(*GraceFalse, andFalse));
        }
    }
}