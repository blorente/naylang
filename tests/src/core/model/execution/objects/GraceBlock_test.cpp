//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/execution/objects/GraceBlock.h>
#include <core/model/execution/methods/MethodFactory.h>
#include <core/model/ast/declarations/Declaration.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Grace Block", "[GraceObjects]") {
    std::vector<DeclarationPtr> params;
    std::vector<StatementPtr> body;
    auto emptyMeth = make_meth(params, body);

    SECTION("A Grace Block takes a Method in the constructor, to act as apply()") {
        GraceBlock emptyBlock(emptyMeth);
        REQUIRE(emptyBlock.hasMethod("apply"));
        REQUIRE(emptyBlock.getMethod("apply") == emptyMeth);
    }
}