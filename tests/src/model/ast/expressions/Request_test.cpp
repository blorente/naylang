//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/ast/expressions/Request.h>
#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/expressions/Block.h>

using namespace naylang;

TEST_CASE("Request Expressions", "[Expressions]") {

    auto five = std::make_shared<NumberLiteral>(5);
    auto fiveBlock = std::make_shared<Block>();
    fiveBlock->addStatement(five);
    auto fiveMethod = std::make_shared<MethodDeclaration>("myMethod", fiveBlock);

    SECTION("A Request has a target identifier name and parameter expressions") {
        REQUIRE_NOTHROW(Request req("myMethod", {five}););
    }

    SECTION("A Request can have an empty parameter list") {
        REQUIRE_NOTHROW(Request req("myMethod"););
    }

    SECTION("A Request can return the identifier name and parameter expressions") {
        Request req("myMethod", {five});
        REQUIRE(req.identifier() == "myMethod");
        REQUIRE(req.params() == std::vector<ExpressionPtr>{five});
    }

    SECTION("A Request can be bound to a identifier declaration") {
        Request req("myMethod", {five});
        req.bindTo(*fiveMethod);

        REQUIRE(&req.declaration() == fiveMethod.get());
    }
}


