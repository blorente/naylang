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

    SECTION("A method identifier can accept a string vector and a number of parameters vector") {
        std::vector<std::string> identifiers {
                "Hello",
                "World"
        };
        std::vector<int> params {
                2, 0
        };
        MethodIdentifier method(identifiers, params);

        REQUIRE_NOTHROW(method.canonName());

        SECTION("The string list and param list must be the same size"){
            std::vector<int> wrongParams {
                    2, 0, 3
            };
            REQUIRE_THROWS(MethodIdentifier wrongMethod(identifiers, wrongParams););
        }
    }

    SECTION("The canonical name of a method is the intercalation of identifiers and blanks") {
        std::vector<std::string> identifiers {
                "Hello",
                "World"
        };
        std::vector<int> params {
                2, 0
        };

        MethodIdentifier method(identifiers, params);
        std::string expected{"Hello"};
        expected.append(BLANK_IDENTIFIER).append(BLANK_IDENTIFIER);
        expected.append("World");
        // expected == "Hello(__)(__)World"

        REQUIRE(method.canonName() == expected);
    }
}