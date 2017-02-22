//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/expressions/methods/MethodCall.h>
#include <model/expressions/primitives/Number.h>
#include <model/environment/identifiers/IdentifierFactory.h>

using namespace naylang;

TEST_CASE("Method Calls", "[Expressions]") {
    auto zero = std::make_shared<Number>(0.0);

    SECTION("A method call needs an canonName") {
        std::unique_ptr<MethodIdentifier> name = IdentifierFactory::createMethodIdentifier("myMethod", 0);
        MethodCall call(std::move(name));
    }

    SECTION("A method can contain a parameter list") {
        std::unique_ptr<MethodIdentifier> name = IdentifierFactory::createMethodIdentifier("myMethod", 0);
        MethodCall call(std::move(name), {zero});
    }

    SECTION("A method call returns it's name and parameters") {
        std::unique_ptr<MethodIdentifier> name = IdentifierFactory::createMethodIdentifier("myMethod", 0);
        MethodCall call(std::move(name), {zero});
        REQUIRE(call.getMethodName() == *name);
        REQUIRE(call.getParameters().size() == 1);
        REQUIRE(call.getParameters()[0] == zero);
    }
}