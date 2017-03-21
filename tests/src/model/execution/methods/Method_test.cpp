//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/execution/methods/Method.h>
#include <model/ast/NodeFactory.h>
#include <model/evaluators/ExecutionEvaluator.h>
#include <model/execution/objects/GraceBoolean.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Method", "[Methods]") {

    auto fiveBlock = make_node<Block>();
    SECTION("A method takes a Block") {
        REQUIRE_NOTHROW(Method meth(fiveBlock););
    }

    SECTION("A method can return it's code") {
        Method meth(fiveBlock);
        REQUIRE(meth.code() == fiveBlock);
    }

    SECTION("A method has a respond function, that returns Done by default") {
        Method meth(fiveBlock);
        ExecutionEvaluator eval;
        GraceBoolean tru(true);
        MethodRequest req("self");
        auto ret = meth.respond(eval, tru, req);
        REQUIRE(ret->isDone());
    }

    SECTION("A method can return it's parameter definitions") {
        Method meth(fiveBlock);
        REQUIRE_NOTHROW(std::equal(meth.params().begin(), meth.params().end(), fiveBlock->params().begin()));
    }
}