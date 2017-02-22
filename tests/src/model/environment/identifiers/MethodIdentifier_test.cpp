//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"
#include <model/environment/identifiers/MethodIdentifier.h>

using namespace naylang;

TEST_CASE("Method Identifiers", "[Environment]") {
    SECTION("A method identifier can accept a string and a number of parameters") {
        std::string methodName = "foo";
        int params = 2;
        MethodIdentifier method(methodName, params);

        std::string expected = methodName;
        expected.append(BLANK_IDENTIFIER).append(BLANK_IDENTIFIER);

        REQUIRE(method.canonName() == expected);
    }

    // The lists must be the same size
}