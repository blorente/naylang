//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/execution/objects/GraceBoolean.h>
#include <core/model/execution/objects/GraceString.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Grace Boolean", "[GraceObjects]") {
    GraceBoolean bul(true);

    SECTION("A GraceBoolean can return it's raw boolean value") {
        REQUIRE(bul.value());
    }

    SECTION("A GraceBoolean can dispatch the prefix! and &&(_) methods as predefined") {
        ExecutionEvaluator eval;
        REQUIRE(*GraceFalse == *bul.dispatch("prefix!", eval, {}));
        eval.evaluate(*make_node<BooleanLiteral>(true));
        REQUIRE(*GraceTrue == *bul.dispatch("&&(_)", eval, {eval.partial()}));
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

    SECTION("OrOr") {
        MethodRequest orTrue("||(_)", {GraceTrue});
        MethodRequest orFalse("||(_)", {GraceFalse});
        GraceBoolean::OrOr method;

        SECTION("AndAnd returns true iff self || req.params()[0]") {
            REQUIRE(*GraceTrue == *method.respond(*GraceTrue, orTrue));
            REQUIRE(*GraceTrue == *method.respond(*GraceTrue, orFalse));
            REQUIRE(*GraceTrue == *method.respond(*GraceFalse, orTrue));
            REQUIRE(*GraceFalse == *method.respond(*GraceFalse, orFalse));
        }
    }

    SECTION("Not") {
        MethodRequest req("not");
        GraceBoolean::Not method;

        SECTION("Calling Not with self == GraceTrue returns GraceFalse") {
            GraceObjectPtr val = method.respond(*GraceTrue, req);
            REQUIRE(*GraceFalse == *val);
        }

        SECTION("Calling Not with self == GraceFalse returns GraceTrue") {
            GraceObjectPtr val = method.respond(*GraceFalse, req);
            REQUIRE(*GraceTrue == *val);
        }
    }

    SECTION("Misc") {
        GraceBoolean::AsString asStr;

        SECTION("asString returns the string representation of the boolean") {
            MethodRequest str("asString", {});
            REQUIRE(asStr.respond(*GraceTrue, str)->asString().value() == "true");
            REQUIRE(asStr.respond(*GraceFalse, str)->asString().value() == "false");
        }
    }
}

TEST_CASE("Grace Boolean common utils", "[GraceBoolean]") {
    SECTION("Calling prettyPrint on a GraceBoolean returns the value") {
        REQUIRE(GraceTrue->prettyPrint(0) == "true");
        REQUIRE(GraceFalse->prettyPrint(0) == "false");
    }
}