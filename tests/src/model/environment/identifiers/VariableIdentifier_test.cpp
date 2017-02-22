//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/environment/identifiers/Identifier.h>
#include <model/environment/identifiers/VariableIdentifier.h>

using namespace naylang;

TEST_CASE("Variable Identifiers", "[Environment]") {
    VariableIdentifier one("x");
    VariableIdentifier other("y");
    VariableIdentifier anotherOne("x");
    std::vector<std::string> words {"Hello", "World", "Identifier"};

    SECTION("A variable identifier can be initialized with a naked string") {
        VariableIdentifier stringIdentifier("hi");
    }
}