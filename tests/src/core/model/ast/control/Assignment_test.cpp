//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/ast/control/Assignment.h>
#include <core/model/ast/NodeFactory.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Assignment Node", "[Control]") {
    auto four = make_node<NumberLiteral>(4.0);
    auto objRef = make_node<ImplicitRequestNode>("obj");

    SECTION("An Assignment takes the name of the field to assign, and an expression to assign") {
        Assignment node("x", four);
    }

    SECTION("An Assignment can take a request for the scope of the field") {
        Assignment node("x", objRef, four);
    }

    SECTION("An Assignment can retrieve it's scope, field name and value") {
        Assignment node("x", objRef, four);
        REQUIRE(node.field() == "x");
        REQUIRE(node.scope() == objRef);
        REQUIRE(node.value() == four);
    }

    SECTION("If no scope is specified, the scope is self") {
        Assignment node("x", four);
        auto scope = static_cast<ImplicitRequestNode &>(*node.scope());
        REQUIRE(scope.identifier() == "self");
    }
}