//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/execution/objects/UserObject.h>
#include <core/model/execution/objects/GraceNumber.h>
#include <core/model/execution/methods/MethodRequest.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Grace Object Native methods", "[GraceObject]") {
    SECTION("Assignment") {
        GraceObject::Assignment assignment;

        UserObject usr;
        auto six = make_obj<GraceNumber>(6.0);
        auto five = make_obj<GraceNumber>(5.0);
        usr.setField("x", five);
        REQUIRE(usr.getField("x")->asNumber().value() == 5.0);
        MethodRequest req(":=(_)", {six});
        assignment.respond(*usr.getField("x"), req);
        REQUIRE(usr.getField("x")->asNumber().value() == 6.0);
    }
}