//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/statements/ParameterList.h>
#include <model/statements/VariableDeclaration.h>

using namespace naylang;

TEST_CASE("Parameter List", "[Statements]") {
    auto xDeclaration = std::make_shared<VariableDeclaration>("x");
    auto yDeclaration = std::make_shared<VariableDeclaration>("y");
    auto declarations = {xDeclaration, yDeclaration};

    SECTION("A parameter list accepts a list of VariableDeclaration pointers") {
        REQUIRE_NOTHROW(ParameterList list(declarations));
    }

    SECTION("A parameter list can return a list of VariableDeclaration pointers") {
        ParameterList list(declarations);
        REQUIRE(std::equal(declarations.begin(), declarations.end(), list.parameters().begin()));
    }
}



