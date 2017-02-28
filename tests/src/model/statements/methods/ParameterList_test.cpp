//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/statements/methods/ParameterList.h>
#include <model/statements/VariableDeclaration.h>

using namespace naylang;

TEST_CASE("Parameter List", "[Statements]") {
    auto xDeclaration = std::make_shared<VariableDeclaration>("x");
    auto yDeclaration = std::make_shared<VariableDeclaration>("y");
    auto declarations = {xDeclaration, yDeclaration};
    auto declarationsReverse = {yDeclaration, xDeclaration};
    auto declarationsShort = {xDeclaration};

    SECTION("A parameter list can be empty") {
        REQUIRE_NOTHROW(ParameterList empty());
    }

    SECTION("A parameter list accepts a list of VariableDeclaration pointers") {
        REQUIRE_NOTHROW(ParameterList list(declarations));
    }

    SECTION("A parameter list can return a list of VariableDeclaration pointers") {
        ParameterList list(declarations);
        REQUIRE(std::equal(declarations.begin(), declarations.end(), list.parameters().begin()));
    }

    SECTION("Two parameter lists are equal iff they point to the same declarations") {
        ParameterList normal(declarations);
        ParameterList otherNormal(declarations);
        ParameterList reverse(declarationsReverse);
        ParameterList shortList(declarationsShort);

        REQUIRE(normal == otherNormal);
        REQUIRE(normal != reverse);
        REQUIRE(normal != shortList);
    }
}



