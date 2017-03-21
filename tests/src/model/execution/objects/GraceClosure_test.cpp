//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/execution/objects/GraceClosure.h>
#include <model/ast/NodeFactory.h>
#include <model/ast/declarations/VariableDeclaration.h>
#include <model/execution/objects/GraceBoolean.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Grace Closure", "[GraceObjects]") {

    SECTION("A Closure accepts a method to enclose as parameter") {
        MethodPtr meth = make_meth(make_node<Block>());
        GraceClosure closure(meth);
    }

    SECTION("A Closure has all the parameters defined in the block as fields by default") {
        auto block = make_node<Block>();
        auto x = make_node<VariableDeclaration>("x");
        block->addParameter(x);
        MethodPtr meth = make_meth(block);
        GraceClosure closure(meth);
        REQUIRE(closure.hasField("x"));
    }

    SECTION("A Closure has a predefined 'apply' method") {
        auto block = make_node<Block>();
        MethodPtr meth = make_meth(block);
        GraceClosure closure(meth);
        REQUIRE(closure.hasMethod("apply"));
    }

    SECTION("A Values can be assigned to the predefined fields with setField()") {
        auto block = make_node<Block>();
        auto x = make_node<VariableDeclaration>("x");
        block->addParameter(x);
        MethodPtr meth = make_meth(block);
        GraceClosure closure(meth);
        REQUIRE_NOTHROW(closure.setField("x", GraceTrue));
    }
}