//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/statements/VariableDeclaration.h>
#include <model/environment/GraceObject.h>

using namespace naylang;

TEST_CASE("Grace Object", "[Environment]") {
    GraceObject numFive(5.0);
    GraceObject otherFive(5.0);
    GraceObject numSix(6.0);

    SECTION("Empty objects are initially undefined") {
        GraceObject undef;

        REQUIRE(undef.isUndefined());
    }

    SECTION("Grace objects can be initialized with numbers") {
        GraceObject zero(0.0);
    }

    SECTION("Grace number objects are equal iff their numbers are the same") {
        REQUIRE(numFive == otherFive);
        REQUIRE(numSix != numFive);
    }

    SECTION("Grace objects can be initialized with methods") {
        auto xDecl = std::make_shared<VariableDeclaration>("x");
        GraceObject shortMethod(xDecl);
    }

    SECTION("Two method objects are == iff they point to the same expression") {
        auto xDecl = std::make_shared<VariableDeclaration>("x");
        auto yDecl = std::make_shared<VariableDeclaration>("y");

        GraceObject methodOne(xDecl);
        GraceObject methodTwo(yDecl);
        GraceObject methodThree(xDecl);

        REQUIRE(methodOne == methodThree);
        REQUIRE(methodOne != methodTwo);
    }
}