//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"
#include <model/evaluators/ExecutionEvaluator.h>
#include <model/ast/expressions/primitives/BooleanLiteral.h>
#include <model/execution/objects/GraceBoolean.h>

using namespace naylang;

TEST_CASE("Execution Evaluator", "[Evaluators]") {

    SECTION("An execution evaluator has a stack of GraceObjects") {
        ExecutionEvaluator eval;
        REQUIRE(eval.objectStack().size() == 0);
    }

    SECTION("Evaluating a BooleanLiteral expression places a GraceBoolean on the stack") {
        ExecutionEvaluator eval;
        BooleanLiteral tru(true);
        REQUIRE_NOTHROW(eval.evaluate(tru));
        REQUIRE(eval.objectStack().top()->asBoolean().value());
    }
}