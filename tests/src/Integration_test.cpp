//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#define CATCH_CONFIG_MAIN

#include <model/Evaluator.h>
#include <model/evaluators/GraceEvaluator.h>
#include "catch.h"

using namespace naylang;

TEST_CASE( "Composite arithmetic operations", "[Integration Tests]" ) {
    GraceEvaluator evaluator;

    auto two = std::make_shared<Number>(2.0);
    auto minusOne = std::make_shared<Number>(-1.0);
    auto six = std::make_shared<Number>(6.0);
    auto zero = std::make_shared<Number>(0.0);

    auto sumToOne = std::make_shared<Addition>(two, minusOne);
    auto minusSix = std::make_shared<Subtraction>(zero, six);
    auto minusSeven = std::make_shared<Subtraction>(minusSix, sumToOne);
    auto toPlusSeven = std::make_shared<Multiplication>(minusSeven, minusOne);
    auto toThreePointFive = std::make_shared<Division>(toPlusSeven, two);

    REQUIRE_NOTHROW(evaluator.evaluate(*toThreePointFive));
    REQUIRE(evaluator.getPartialDouble() == 3.5);
}

TEST_CASE( "Arithmetic operations with assignments", "[Integration Tests]") {
    GraceEvaluator evaluator;

    auto two = std::make_shared<Number>(2.0);
    auto minusOne = std::make_shared<Number>(-1.0);
    auto minusSeven = std::make_shared<Number>(-7.0);

    // These are not evaluated directly
    auto three = std::make_shared<Subtraction>(two, minusOne);

    // Must be evaluated directly
    auto constY = std::make_shared<Constant>("y", three);
    auto declareX = std::make_shared<VariableDeclaration>("x");
    auto assignX = std::make_shared<Assignment>("x", minusSeven);

    // Not evaluated directly
    auto refY = std::make_shared<VariableReference>("y");
    auto refX = std::make_shared<VariableReference>("x");
    auto yTimesX = std::make_shared<Multiplication>(refY, refX);

    auto reassignX = std::make_shared<Assignment>("x", yTimesX);

    // Evaluations
    REQUIRE_NOTHROW(evaluator.evaluate(*constY));   // y = 3;
    REQUIRE_NOTHROW(evaluator.evaluate(*declareX)); // y = 3; x = NoInit
    REQUIRE_NOTHROW(evaluator.evaluate(*assignX));  // y = 3; x = -7
    REQUIRE_NOTHROW(evaluator.evaluate(*reassignX));// y = 3; x = y * x = -21

    // Check the value of X
    REQUIRE_NOTHROW(evaluator.evaluate(*refX));
    REQUIRE(evaluator.getPartialDouble() == -21.0);
}
