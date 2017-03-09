//
// Copyright (c) 1/5/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/declarations/MethodDeclaration.h>
#include "catch.h"


using namespace naylang;

TEST_CASE("Method Declaration", "[Declarations]") {
    auto five = std::make_shared<NumberLiteral>(5.0);
    auto numberBody = std::make_shared<Block>();

    SECTION("A Method Declaration takes a canonicalName and a body block") {
        MethodDeclaration decl("myMethod", numberBody);
    }

    SECTION("A Method Declaration can return it's name and body") {
        MethodDeclaration decl("myMethod", numberBody);
        REQUIRE(decl.name() == "myMethod");
        REQUIRE(decl.body() == numberBody);
    }

}