//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/execution/objects/GraceNumber.h>
#include <model/execution/objects/GraceBoolean.h>
#include <model/execution/Definitions.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Grace Number", "[GraceObjects]") {
    GraceNumber num(5.0);
}

TEST_CASE("Grace Number Native Methods", "[GraceNumber]") {
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
            auto six = make_obj<GraceNumber>(6.0);

            MethodRequest equalsSix("!=(_)", {six});
            MethodRequest equalsFive("!=(_)", {otherFive});

            REQUIRE(*GraceFalse == *method.respond(five, equalsFive));
            REQUIRE(*GraceTrue == *method.respond(five, equalsSix));
        }
    }

    SECTION("Arithmetic") {
        GraceNumber::Add add;
        GraceNumber::Sub sub;
        GraceNumber::Mul mul;
        GraceNumber::Div div;
        GraceNumber::Mod mod;
        GraceNumber::Pow pow;

        auto five = make_obj<GraceNumber>(5.0);
        auto six = make_obj<GraceNumber>(6.0);

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
}