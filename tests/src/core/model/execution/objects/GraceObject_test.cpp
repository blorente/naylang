//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <core/model/execution/objects/UserObject.h>
#include <core/model/execution/objects/GraceNumber.h>
#include <core/model/execution/objects/GraceString.h>
#include <core/model/execution/objects/GraceBoolean.h>

#include <core/model/execution/methods/MethodRequest.h>
#include <core/model/execution/methods/MethodFactory.h>

using namespace naylang;

TEST_CASE("Grace Object Native methods", "[GraceObject]") {
    auto six = make_obj<GraceNumber>(6.0);
    auto five = make_obj<GraceNumber>(5.0);
    auto hi = make_obj<GraceString>("Hi");

    SECTION("Assignment") {

        SECTION("Number Assignment") {
            UserObject usr;
            usr.setField("x", five);
            REQUIRE(usr.getField("x")->asNumber().value() == 5.0);
            MethodRequest req(":=(_)", {six});
            GraceNumber::Assignment ass;
            ass.respond(*usr.getField("x"), req);
            REQUIRE(usr.getField("x")->asNumber().value() == 6.0);
        }

        SECTION("Object assignment") {
            UserObject one;
            auto other = make_obj<UserObject>();

            other->setField("x", six);
            other->setField("y", hi);
            other->setField("z", GraceTrue);
            other->addMethod("add", make_meth(make_node<Block>()));

            MethodRequest req(":=(_)", {other});
            assignment.respond(one, req);

            REQUIRE(one.hasField("x"));
            REQUIRE(one.hasField("y"));
            REQUIRE(one.hasField("z"));
            REQUIRE(one.hasMethod("add"));
            REQUIRE(one.getField("x")->asNumber().value() == 6.0);
            REQUIRE(one.getField("y")->asString().value() == "Hi");
            REQUIRE(one.getField("z")->asBoolean().value() == true);
            REQUIRE(one.getMethod("add")->params().size() == 0);
            REQUIRE(one.getMethod("add")->code().size() == 0);
        }
    }
}