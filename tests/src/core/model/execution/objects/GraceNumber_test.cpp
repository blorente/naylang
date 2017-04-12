//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/execution/objects/GraceNumber.h>
#include <core/model/execution/objects/GraceBoolean.h>
#include <core/model/execution/objects/GraceString.h>
#include <core/model/execution/Definitions.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Grace Number", "[GraceObjects]") {
    GraceNumber num(5.0);
}

TEST_CASE("Grace Number Native Methods", "[GraceNumber]") {
    auto five = make_obj<GraceNumber>(5.0);
    auto six = make_obj<GraceNumber>(6.0);

    SECTION("Equals") {
        GraceNumber::Equals method;

        SECTION("==(_) returns GraceTrue iff they both represent the same number") {
            GraceNumber five(5.0);
            auto otherFive = make_obj<GraceNumber>(5.0);
            auto six = make_obj<GraceNumber>(6.0);

            MethodRequest equalsSix("==(_)", {six});
            MethodRequest equalsFive("==(_)", {otherFive});

            REQUIRE(*GraceTrue== *method.respond(five, equalsFive));
            REQUIRE(*GraceFalse == *method.respond(five, equalsSix));
        }
    }

    SECTION("NotEquals") {
        GraceNumber::NotEquals method;

        SECTION("!=(_) returns GraceTrue iff they both represent different numbers") {
            GraceNumber five(5.0);
            auto otherFive = make_obj<GraceNumber>(5.0);

            MethodRequest equalsSix("!=(_)", {six});
            MethodRequest equalsFive("!=(_)", {otherFive});

            REQUIRE(*GraceFalse == *method.respond(five, equalsFive));
            REQUIRE(*GraceTrue == *method.respond(five, equalsSix));
        }
    }

    SECTION("Arithmetic") {
        GraceNumber::Negative neg;
        GraceNumber::Add add;
        GraceNumber::Sub sub;
        GraceNumber::Mul mul;
        GraceNumber::Div div;
        GraceNumber::Mod mod;
        GraceNumber::Pow pow;

        SECTION("prefix- returns the negative version of self") {
            MethodRequest req("prefix-", {});
            REQUIRE(neg.respond(*six, req)->asNumber().value() == -6.0);
        }

        SECTION("+(_) returns the sum of self and the first parameter") {
            MethodRequest req("+(_)", {five});
            REQUIRE(add.respond(*six, req)->asNumber().value() == 11.0);
        }

        SECTION("-(_) returns the subtraction of self and the first parameter") {
            MethodRequest req("-(_)", {five});
            REQUIRE(sub.respond(*six, req)->asNumber().value() == 1.0);
        }

        SECTION("*(_) returns the product of self and the first parameter") {
            MethodRequest req("*(_)", {five});
            REQUIRE(mul.respond(*six, req)->asNumber().value() == 30.0);
        }

        SECTION("/(_) returns the real division of self and the first parameter") {
            MethodRequest req("/(_)", {five});
            REQUIRE(div.respond(*six, req)->asNumber().value() == 1.2);
        }

        SECTION("%(_) returns the integer modulus of self and the first parameter") {
            MethodRequest req("%(_)", {five});
            REQUIRE(mod.respond(*six, req)->asNumber().value() == 1.0);
        }

        SECTION("^(_) returns self to the first parameter") {
            MethodRequest req("^(_)", {five});
            REQUIRE(pow.respond(*six, req)->asNumber().value() == 7776.0);
        }
    }

    SECTION("Relational") {
        GraceNumber::Greater greater;
        GraceNumber::GreaterEq greaterEq;
        GraceNumber::Less less;
        GraceNumber::LessEq lessEq;

        SECTION(">(_) return GraceTrue iff self is strictly greater than the first parameter") {
            MethodRequest reqTrue(">(_)", {five});
            MethodRequest reqFalse(">(_)", {six});
            REQUIRE(*GraceTrue == *greater.respond(*six, reqTrue));
            REQUIRE(*GraceFalse == *greater.respond(*six, reqFalse));
        }

        SECTION(">=(_) return GraceTrue iff self is greater or equal than the first parameter") {
            MethodRequest reqTrue(">=(_)", {five});
            MethodRequest reqEq(">=(_)", {six});
            REQUIRE(*GraceTrue == *greaterEq.respond(*six, reqTrue));
            REQUIRE(*GraceTrue == *greaterEq.respond(*six, reqEq));
        }

        SECTION("<(_) return GraceTrue iff self is strictly less than the first parameter") {
            MethodRequest reqFive("<(_)", {five});
            MethodRequest reqSix("<(_)", {six});
            REQUIRE(*GraceFalse == *less.respond(*six, reqFive));
            REQUIRE(*GraceFalse == *less.respond(*six, reqSix));
        }

        SECTION("<=(_) return GraceTrue iff self is less or equal than the first parameter") {
            MethodRequest reqFalse("<=(_)", {five});
            MethodRequest reqTrue("<=(_)", {six});
            REQUIRE(*GraceFalse == *lessEq.respond(*six, reqFalse));
            REQUIRE(*GraceTrue == *lessEq.respond(*six, reqTrue));
        }
    }

    SECTION("Misc") {
        GraceNumber::AsString asStr;

        SECTION("asString returns the string representation of the number") {
            MethodRequest str("asString", {});
            REQUIRE(asStr.respond(*five, str)->asString().value() == "5.000000");
        }
    }
}

TEST_CASE("Grace Number common utils", "[GraceNumber]") {
    SECTION("Calling prettyPrint on a GraceNumber returns the value") {
        GraceNumber num(5);
        REQUIRE(num.prettyPrint(0) == "5.000000");
    }
}