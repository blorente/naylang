//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/expressions/methods/MethodCall.h>
#include <model/expressions/primitives/Number.h>

using namespace naylang;

TEST_CASE("Method Calls", "[Expressions]") {
    Identifier name("myMethod");
    auto zero = std::make_shared<Number>(0.0);

    SECTION("A method call needs an identifier") {
        MethodCall call(name);
    }

    SECTION("A method can contain a parameter list") {
        MethodCall call(name, {zero});
    }

    SECTION("A method call returns it's name and parameters") {
        MethodCall call(name, {zero});
        REQUIRE(call.getMethodName() == name);
        REQUIRE(call.getParameters().size() == 1);
        REQUIRE(call.getParameters()[0] == zero);
    }
}