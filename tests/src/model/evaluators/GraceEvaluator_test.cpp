//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <iostream>
#include "catch.h"

#include "model/evaluators/GraceEvaluator.h"

using namespace naylang;

TEST_CASE("Grace Evaluator", "[Evaluators]") {
    GraceEvaluator eval;

    auto five = std::make_shared<Number>(5.0);
    auto two = std::make_shared<Number>(2.0);
    auto minusOne = std::make_shared<Number>(-1.0);
    auto six = std::make_shared<Number>(6.0);
    auto zero = std::make_shared<Number>(0.0);
    auto tru = std::make_shared<Boolean>(true);

    SECTION("A Number expression just stores the value") {
        Number fiveNat(5.0);
        REQUIRE_NOTHROW(eval.evaluate(fiveNat));
        REQUIRE(eval.getPartialDouble() == fiveNat.value());
    }

    SECTION("If the identifier of a constant already exists in the environment, it throws an exception") {
        Constant xConstant("x", six);
        REQUIRE_NOTHROW(eval.evaluate(xConstant));
        REQUIRE_THROWS(eval.evaluate(xConstant));
    }

    SECTION("A variable declaration must be made before an assignment can be done") {
        Assignment xAssignment("x", six);
        VariableDeclaration xDeclaration("x");
        REQUIRE_THROWS(eval.evaluate(xAssignment));
        REQUIRE_NOTHROW(eval.evaluate(xDeclaration));
        REQUIRE_NOTHROW(eval.evaluate(xAssignment));
    }

    SECTION("A variable reference throws if the value is invalid (not initialized)") {
        VariableDeclaration xDeclaration("x");
        VariableReference xReference("x");
        REQUIRE_NOTHROW(eval.evaluate(xDeclaration));
        REQUIRE_THROWS(eval.evaluate(xReference));
    }

    SECTION("A variable reference places the value in the partial") {
        VariableDeclaration xDeclaration("x");
        VariableReference xReference("x");
        Assignment xAssignment("x", six);
        REQUIRE_NOTHROW(eval.evaluate(xDeclaration));
        REQUIRE_NOTHROW(eval.evaluate(xAssignment));
        REQUIRE_NOTHROW(eval.evaluate(xReference));
        REQUIRE(eval.getPartialDouble() == 6.0);
    }

    SECTION("The evaluator throws an exception when dividing by 0") {
        Division divideByZero(six, zero);
        REQUIRE_THROWS(eval.evaluate(divideByZero));
    }

    SECTION("The evaluator places the value of a Boolean in a partial") {
        REQUIRE_NOTHROW(eval.evaluate(*tru));
        REQUIRE(eval.getPartialDouble());
    }

}