//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/ast/expressions/VariableReference.h>
#include <model/ast/declarations/VariableDeclaration.h>
#include <model/ast/NodeFactory.h>

using namespace naylang;

TEST_CASE("Variable Reference Expressions", "[Expressions]") {
    SECTION("A Variable Reference accepts a name") {
        REQUIRE_NOTHROW(VariableReference referenceY("y"););
    }

    SECTION("A Variable Reference can return it's a name") {
        VariableReference referenceY("y");

        REQUIRE(referenceY.identifier() == "y");
    }

    SECTION("A Variable Reference can be bound to a Declaration") {
        auto decY = make_node<VariableDeclaration>("y");
        VariableReference refY("y");
        refY.bindTo(*decY);
        REQUIRE(&refY.declaration() == decY.get());
    }
}
