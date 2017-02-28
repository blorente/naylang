//
// Copyright (c) 1/5/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/statements/methods/MethodDeclaration.h>
#include <model/expressions/primitives/Number.h>
#include <model/expressions/ExpressionBlock.h>
#include <model/environment/identifiers/IdentifierFactory.h>

using namespace naylang;

TEST_CASE("Method Declarations", "[Expressions]") {
    auto five = std::make_shared<Number>(5.0);
    auto numberBody = std::make_shared<ExpressionBlock>();

    SECTION("A method delaration takes an canonName and a body expression") {
        auto name = IdentifierFactory::createMethodIdentifier("myMethod", 0);
        numberBody->addInstruction(five);
        MethodDeclaration method(std::move(name), numberBody);
    }

    SECTION("A method declaration returns it's name and body") {
        auto name = IdentifierFactory::createMethodIdentifier("myMethod", 0);
        numberBody->addInstruction(five);
        MethodDeclaration method(std::move(name), numberBody);

        REQUIRE(method.getCanonName()->canonName() == "myMethod");
        REQUIRE(static_cast<Number &>(*(method.getBody()->expressions()[0])).value() == 5.0);
    }
}