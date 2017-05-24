//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/execution/methods/Method.h>
#include <core/model/ast/NodeFactory.h>
#include <core/model/execution/objects/GraceBoolean.h>
#include <core/model/evaluators/ExecutionEvaluator.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Method", "[Methods]") {

    auto fiveBlock = make_node<Block>();
    SECTION("A method can take a Block") {
        REQUIRE_NOTHROW(Method meth(fiveBlock););
    }

    SECTION("A method can take a list of parameters and a body") {
        REQUIRE_NOTHROW(Method meth({}, {}));
    }

    SECTION("A method can return it's code") {
        Method meth(fiveBlock);
        REQUIRE(std::equal(meth.code().begin(), meth.code().end(), fiveBlock->body().begin()));
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

    SECTION("A method can prettyPrint itself, by recieving it's name") {
        auto block = make_node<Block>();
        block->addParameter(make_node<VariableDeclaration>("x"));
        block->addParameter(make_node<VariableDeclaration>("y"));
        block->addParameter(make_node<VariableDeclaration>("zzz"));

        // Body ignored for prettyPrint
        block->addStatement(make_node<NumberLiteral>(5.0));
        Method meth(block);
        REQUIRE(meth.prettyPrint("two(_,_)things(_)", 0) == "method two(x,y)things(zzz) { }");
    }
}