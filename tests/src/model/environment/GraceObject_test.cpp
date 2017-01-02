//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include "model/environment/GraceObject.h"
#include "model/environment/GraceObjectFactory.h"

using namespace naylang;

TEST_CASE("Value", "[Environment]") {
    SECTION("A Value can only hold a double") {
        auto five = GraceObjectFactory::createNumber(5.0);
        REQUIRE(five.value() == 5.0);
    }

    SECTION("Two Values are equal iff their doubles are equal") {
        auto five = GraceObjectFactory::createNumber(5.0);
        auto anotherFive = GraceObjectFactory::createNumber(5.0);
        auto one = GraceObjectFactory::createNumber(1.0);
        REQUIRE(five == anotherFive);
        REQUIRE(!(five == one));
    }
}