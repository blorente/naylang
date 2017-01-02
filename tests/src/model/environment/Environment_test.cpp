//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//


#include "catch.h"

#include "model/environment/Environment.h"
#include "model/environment/Value.h"

using namespace naylang;

TEST_CASE("Environment", "[Environment]") {

    Environment env;

    SECTION("An Environment is initially empty") {
        REQUIRE(env.size() == 0);
    }

    SECTION("Trying to get an unbound value raises an exception") {
        Identifier badIdentifier("baaad");
        REQUIRE_THROWS(env.get(badIdentifier));
    }

    SECTION("Once a value has been inserted, you can get() it") {
        Identifier x("x");
        Value five(5.0);
        env.bind(x, five);
        REQUIRE(env.get(x).value() == five.value());
    }

    SECTION("After bind(), the a value can be change()d") {
        Identifier x("x");
        Value five(5.0);
        Value three(3.0);
        env.bind(x, five);
        REQUIRE(env.get(x).value() == five.value());
        REQUIRE_THROWS(env.bind(x, three));
        env.change(x, three);
        REQUIRE(env.get(x).value() == three.value());
    }

    SECTION("All calls to bind() after the first with an identifier throw") {
        Identifier x("x");
        Value five(5.0);
        Value three(3.0);
        env.bind(x, five);
        REQUIRE_THROWS(env.bind(x, three));
        REQUIRE_THROWS(env.bind(x, five));
    }

    SECTION("A call to change() will fail if the binding is not created") {
        Identifier x("x");
        Value five(5.0);
        REQUIRE_THROWS(env.change(x, five));
    }

}