//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/execution/objects/GraceClosure.h>
#include <core/model/ast/NodeFactory.h>
#include <core/model/ast/declarations/VariableDeclaration.h>
#include <core/model/execution/objects/GraceBoolean.h>
#include <core/model/execution/methods/MethodFactory.h>
#include <core/model/evaluators/ExecutionEvaluator.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Grace Closure", "[GraceObjects]") {
    ExecutionEvaluator context;
    SECTION("A Closure accepts a method to enclose as parameter and a context evaluator") {
        MethodPtr meth = make_meth(make_node<Block>());
        GraceClosure closure("blankMethod", meth, context);
    }

    SECTION("If the empty constructor is used, fields have to be defined elsewhere") {
        GraceClosure closure;
        REQUIRE(!closure.hasField("x"));
    }

    SECTION("A Closure has all the parameters defined in the block as fields by default") {
        auto block = make_node<Block>();
        auto x = make_node<VariableDeclaration>("x");
        block->addParameter(x);
        MethodPtr meth = make_meth(block);
        GraceClosure closure("methodWithParam", meth, context);
        REQUIRE(closure.hasField("x"));
    }

    SECTION("A Closure defines the passed (enclosed) method") {
        auto block = make_node<Block>();
        MethodPtr meth = make_meth(block);
        GraceClosure closure("enclosed", meth, context);
        REQUIRE(closure.hasMethod("enclosed"));
    }

    SECTION("A Value can be assigned to the predefined fields with setField()") {
        auto block = make_node<Block>();
        auto x = make_node<VariableDeclaration>("x");
        block->addParameter(x);
        MethodPtr meth = make_meth(block);
        GraceClosure closure("predefined", meth, context);
        REQUIRE_NOTHROW(closure.setField("x", GraceTrue));
    }

    SECTION("Field values can be retrieved") {
        auto block = make_node<Block>();
        auto x = make_node<VariableDeclaration>("x");
        block->addParameter(x);
        MethodPtr meth = make_meth(block);
        GraceClosure closure("retrieveMe", meth, context);
        REQUIRE_NOTHROW(closure.getField("x"));
    }
}