//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#define CATCH_CONFIG_MAIN

#include <model/Evaluator.h>
#include <model/evaluators/GraceEvaluator.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Composite arithmetic operations", "[Integration Tests]" ) {
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

TEST_CASE("Arithmetic operations with assignments", "[Integration Tests]") {
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

    // Check the asNumber of X
    REQUIRE_NOTHROW(evaluator.evaluate(*refX));
    REQUIRE(evaluator.getPartialDouble() == -21.0);
}

TEST_CASE("ExpressionBlocks with IfThenElse Expressions", "[Integration Tests]") {
    /* x=5; y=6;
     * if (true) { x=x+1; }
     * else { y=0; }
     * y = y+1;
     * if (false) { x=0; }
     * else { x=y+1; y=y+1; }
     * require(x == 8);
     * require(y == 8);
     */
    GraceEvaluator evaluator;
    auto xDeclaration = std::make_shared<VariableDeclaration>("x");
    auto yDeclaration = std::make_shared<VariableDeclaration>("y");
    auto xReference = std::make_shared<VariableReference>("x");
    auto yReference = std::make_shared<VariableReference>("y");

    auto tru = std::make_shared<Boolean>(true);
    auto fals = std::make_shared<Boolean>(false);
    auto one = std::make_shared<Number>(1.0);
    auto zero = std::make_shared<Number>(0.0);
    auto five = std::make_shared<Number>(5.0);
    auto six = std::make_shared<Number>(6.0);

    // x=5; y=6;
    auto xEqualsFive = std::make_shared<Assignment>("x", five);
    auto yEqualsSix = std::make_shared<Assignment>("y", six);

    // if (true) { x=x+1; }
    auto ITE1ThenBlock = std::make_shared<ExpressionBlock>();
    auto xPlusOne = std::make_shared<Addition>(xReference, one);
    auto xEqualsXPlusOne = std::make_shared<Assignment>("x", xPlusOne);
    ITE1ThenBlock->addInstruction(xEqualsXPlusOne);

    // else { y=0; }
    auto ITE1ElseBlock = std::make_shared<ExpressionBlock>();
    auto yEqualsZero = std::make_shared<Assignment>("y", zero);
    ITE1ElseBlock->addInstruction(yEqualsZero);

    auto ITE1 = std::make_shared<IfThenElse>(tru, ITE1ThenBlock, ITE1ElseBlock);

    // y = y+1;
    auto yPlusOne = std::make_shared<Addition>(yReference, one);
    auto yEqualsYPlusOne = std::make_shared<Assignment>("y", yPlusOne);

    // if (false) { x=0; }
    auto ITE2ThenBlock = std::make_shared<ExpressionBlock>();
    auto xEqualsZero = std::make_shared<Assignment>("x", zero);
    ITE2ThenBlock->addInstruction(xEqualsZero);

    // else { x=y+1; y=y+1; }
    auto ITE2ElseBlock = std::make_shared<ExpressionBlock>();
    auto xEqualsYPlusOne = std::make_shared<Assignment>("x", yPlusOne);
    ITE2ElseBlock->addInstruction(xEqualsYPlusOne);
    ITE2ElseBlock->addInstruction(yEqualsYPlusOne);

    auto ITE2 = std::make_shared<IfThenElse>(fals, ITE2ThenBlock, ITE2ElseBlock);

    auto programBlock = std::make_shared<ExpressionBlock>();
    programBlock->addInstruction(xDeclaration);
    programBlock->addInstruction(yDeclaration);
    programBlock->addInstruction(xEqualsFive);
    programBlock->addInstruction(yEqualsSix);
    programBlock->addInstruction(ITE1);
    programBlock->addInstruction(yEqualsYPlusOne);
    programBlock->addInstruction(ITE2);

    REQUIRE_NOTHROW(evaluator.evaluate(*programBlock));
    REQUIRE_NOTHROW(xReference);
    REQUIRE(evaluator.getPartialDouble() == 8.0);
    REQUIRE_NOTHROW(yReference);
    REQUIRE(evaluator.getPartialDouble() == 8.0);
}
