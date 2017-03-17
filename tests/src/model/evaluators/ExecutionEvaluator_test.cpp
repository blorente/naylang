//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"
#include <model/evaluators/ExecutionEvaluator.h>
#include <model/ast/expressions/primitives/BooleanLiteral.h>
#include <model/ast/expressions/RequestNode.h>
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

    SECTION("Evaluating {!true} places GraceFalse on top of the stack") {
        ExecutionEvaluator eval;
        auto tru = make_node<BooleanLiteral>(true);
        std::vector<ExpressionPtr> prefParams{tru};
        auto prefNot = make_node<RequestNode>("prefix!", prefParams);
        eval.evaluate(*prefNot);

        REQUIRE(*GraceFalse == *eval.objectStack().top());
    }
}