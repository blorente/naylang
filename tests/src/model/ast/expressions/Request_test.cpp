//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/ast/expressions/Request.h>
#include <model/ast/expressions/primitives/NumberLiteral.h>

using namespace naylang;

TEST_CASE("Request Expressions", "[Expressions]") {

    auto five = std::make_shared<NumberLiteral>(5);

    SECTION("A Request has a target method name and parameter expressions") {
        REQUIRE_NOTHROW(Request req("myMethod", {five}););
    }

    SECTION("A Request can return the method name and parameter expressions") {
        Request req("myMethod", {five});
        REQUIRE(req.method() == "myMethod");
        REQUIRE(req.params() == std::vector<ExpressionPtr>{five});
    }
}


