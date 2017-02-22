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
        std::unique_ptr<Identifier> badIdentifier = IdentifierFactory::createVariableIdentifier("baaad");
        REQUIRE_THROWS(env.get(badIdentifier));
    }

    SECTION("Once a asNumber has been inserted, you can get() it") {
        std::unique_ptr<Identifier> x = IdentifierFactory::createVariableIdentifier("x");
        env.bind(std::move(x), five);
        REQUIRE(env.get(x).asNumber() == five.asNumber());
    }

    SECTION("After bind(), the a asNumber can be change()d") {
        std::unique_ptr<Identifier> x = IdentifierFactory::createVariableIdentifier("x");
        env.bind(std::move(x), five);
        REQUIRE(env.get(x).asNumber() == five.asNumber());
        REQUIRE_THROWS(env.bind(std::move(x), three));
        env.change(x, three);
        REQUIRE(env.get(x).asNumber() == three.asNumber());
    }

    SECTION("All calls to bind() after the first with the same canonName throw") {
        std::unique_ptr<Identifier> x = IdentifierFactory::createVariableIdentifier("x");
        env.bind(std::move(x), five);
        REQUIRE_THROWS(env.bind(std::move(x), three));
        REQUIRE_THROWS(env.bind(std::move(x), five));
    }

    SECTION("A call to change() will fail if the binding is not created") {
        std::unique_ptr<Identifier> x = IdentifierFactory::createVariableIdentifier("x");
        REQUIRE_THROWS(env.change(x, five));
    }

    SECTION("An environment accepts a parent environment as a constructor parameter") {
        std::unique_ptr<Identifier> x = IdentifierFactory::createVariableIdentifier("x");
        std::unique_ptr<Identifier> y = IdentifierFactory::createVariableIdentifier("y");
        auto parent = std::make_shared<Environment>();
        parent->bind(std::move(y), five);
        Environment child(parent);
        child.bind(std::move(x), three);

        REQUIRE(child.get(y).asNumber() == 5.0);
    }

    SECTION("A child environment can access the parent's bindings, but not vice versa") {
        std::unique_ptr<Identifier> x = IdentifierFactory::createVariableIdentifier("x");
        std::unique_ptr<Identifier> y = IdentifierFactory::createVariableIdentifier("y");
        auto parent = std::make_shared<Environment>();
        parent->bind(std::move(y), five);
        Environment child(parent);
        child.bind(std::move(x), three);

        REQUIRE(parent->get(y).asNumber() == 5.0);
        REQUIRE_THROWS(parent->get(x));
        REQUIRE(child.get(y).asNumber() == 5.0);
        REQUIRE(child.get(x).asNumber() == 3.0);
    }

    SECTION("A child environment cannot create bindings that are in the parent") {
        std::unique_ptr<Identifier> x = IdentifierFactory::createVariableIdentifier("x");
        std::unique_ptr<Identifier> y = IdentifierFactory::createVariableIdentifier("y");
        auto parent = std::make_shared<Environment>();
        parent->bind(std::move(y), five);
        Environment child(parent);

        REQUIRE_NOTHROW(child.bind(std::move(x), three));
        REQUIRE_THROWS(child.bind(std::move(y), three));
    }

}