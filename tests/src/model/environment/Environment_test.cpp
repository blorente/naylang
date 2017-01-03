//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//


#include "catch.h"
#include "model/environment/Environment.h"

#include <model/environment/GraceObjectFactory.h>

using namespace naylang;

TEST_CASE("Environment", "[Environment]") {

    Environment env;

    SECTION("An Environment is initially empty") {
        REQUIRE(env.size() == 0);
    }

    SECTION("Trying to get an unbound asNumber raises an exception") {
        Identifier badIdentifier("baaad");
        REQUIRE_THROWS(env.get(badIdentifier));
    }

    SECTION("Once a asNumber has been inserted, you can get() it") {
        Identifier x("x");
        auto five = GraceObjectFactory::createNumber(5.0);
        env.bind(x, five);
        REQUIRE(env.get(x).asNumber() == five.asNumber());
    }

    SECTION("After bind(), the a asNumber can be change()d") {
        Identifier x("x");
        auto five = GraceObjectFactory::createNumber(5.0);
        auto three = GraceObjectFactory::createNumber(3.0);
        env.bind(x, five);
        REQUIRE(env.get(x).asNumber() == five.asNumber());
        REQUIRE_THROWS(env.bind(x, three));
        env.change(x, three);
        REQUIRE(env.get(x).asNumber() == three.asNumber());
    }

    SECTION("All calls to bind() after the first with an identifier throw") {
        Identifier x("x");
        auto five = GraceObjectFactory::createNumber(5.0);
        auto three = GraceObjectFactory::createNumber(3.0);
        env.bind(x, five);
        REQUIRE_THROWS(env.bind(x, three));
        REQUIRE_THROWS(env.bind(x, five));
    }

    SECTION("A call to change() will fail if the binding is not created") {
        Identifier x("x");
        auto five = GraceObjectFactory::createNumber(5.0);
        REQUIRE_THROWS(env.change(x, five));
    }

}