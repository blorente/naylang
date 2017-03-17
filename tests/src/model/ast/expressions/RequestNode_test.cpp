//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/ast/expressions/RequestNode.h>
#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/expressions/Block.h>
#include <model/ast/NodeFactory.h>

using namespace naylang;

TEST_CASE("RequestNode Expressions", "[Expressions]") {

    auto five = make_node<NumberLiteral>(5.0);
    auto fiveBlock = make_node<Block>();
    fiveBlock->addStatement(five);
    auto fiveMethod = make_node<MethodDeclaration>("myMethod", fiveBlock);

    SECTION("A RequestNode has a target identifier name and parameter expressions") {
        REQUIRE_NOTHROW(RequestNode req("myMethod", {five}););
    }

    SECTION("A RequestNode can have an empty parameter list") {
        REQUIRE_NOTHROW(RequestNode req("myMethod"););
    }

    SECTION("A RequestNode can return the identifier name and parameter expressions") {
        RequestNode req("myMethod", {five});
        REQUIRE(req.identifier() == "myMethod");
        REQUIRE(req.params() == std::vector<ExpressionPtr>{five});
    }

    SECTION("A RequestNode can be bound to a identifier declaration") {
        RequestNode req("myMethod", {five});
        req.bindTo(*fiveMethod);

        REQUIRE(&req.declaration() == fiveMethod.get());
    }
}


