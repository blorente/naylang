//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//


#include "catch.h"
#include "model/environment/Environment.h"

#include <model/environment/GraceObjectFactory.h>
#include <model/environment/identifiers/VariableIdentifier.h>
#include <model/environment/identifiers/IdentifierFactory.h>

using namespace naylang;

TEST_CASE("Environment", "[Environment]") {

    Environment env;
    auto five = GraceObjectFactory::createNumber(5.0);
    auto three = GraceObjectFactory::createNumber(3.0);

    SECTION("An Environment is initially empty") {
        REQUIRE(env.size() == 0);
    }

    SECTION("Trying to get an unbound asNumber raises an exception") {
        auto badIdentifier = IdentifierFactory::createVariableIdentifier("baaad");
        REQUIRE_THROWS(env.get(badIdentifier));
    }

    SECTION("Once a asNumber has been inserted, you can get() it") {
        auto x = IdentifierFactory::createVariableIdentifier("x");
        env.bind(x, five);
        REQUIRE(env.get(x).asNumber() == five.asNumber());
    }

    SECTION("After bind(), the a asNumber can be change()d") {
        auto x = IdentifierFactory::createVariableIdentifier("x");
        env.bind(x, five);
        REQUIRE(env.get(x).asNumber() == five.asNumber());
        REQUIRE_THROWS(env.bind(x, three));
        env.change(x, three);
        REQUIRE(env.get(x).asNumber() == three.asNumber());
    }

    SECTION("All calls to bind() after the first with the same canonName throw") {
        auto x = IdentifierFactory::createVariableIdentifier("x");
        env.bind(x, five);
        REQUIRE_THROWS(env.bind(x, three));
        REQUIRE_THROWS(env.bind(x, five));
    }

    SECTION("A call to change() will fail if the binding is not created") {
        auto x = IdentifierFactory::createVariableIdentifier("x");
        REQUIRE_THROWS(env.change(x, five));
    }

    SECTION("An environment accepts a parent environment as a constructor parameter") {
        auto x = IdentifierFactory::createVariableIdentifier("x");
        auto y = IdentifierFactory::createVariableIdentifier("y");
        auto parent = std::make_shared<Environment>();
        parent->bind(y, five);
        Environment child(parent);
        child.bind(std::move(x), three);

        REQUIRE(child.get(y).asNumber() == 5.0);
    }

    SECTION("A child environment can access the parent's bindings, but not vice versa") {
        auto x = IdentifierFactory::createVariableIdentifier("x");
        auto y = IdentifierFactory::createVariableIdentifier("y");
        auto parent = std::make_shared<Environment>();
        parent->bind(y, five);
        Environment child(parent);
        child.bind(x, three);

        REQUIRE(parent->get(y).asNumber() == 5.0);
        REQUIRE_THROWS(parent->get(x));
        REQUIRE(child.get(y).asNumber() == 5.0);
        REQUIRE(child.get(x).asNumber() == 3.0);
    }

    SECTION("A child environment cannot create bindings that are in the parent") {
        auto x = IdentifierFactory::createVariableIdentifier("x");
        auto y = IdentifierFactory::createVariableIdentifier("y");
        auto parent = std::make_shared<Environment>();
        parent->bind(y, five);
        Environment child(parent);

        REQUIRE_NOTHROW(child.bind(x, three));
        REQUIRE_THROWS(child.bind(y, three));
    }

}