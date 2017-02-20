//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/expressions/methods/MethodCall.h>
#include <model/expressions/primitives/Number.h>
#include <model/expressions/ExpressionBlock.h>

using namespace naylang;

TEST_CASE("Method Calls", "[Expressions]") {
    Identifier name("myMethod");
    SECTION("A method call needs an identifier") {
        MethodCall call(name);
    }

    SECTION("A method declaration returns it's name") {
        MethodCall call(name);
        REQUIRE(call.getMethodName() == name);
    }
}