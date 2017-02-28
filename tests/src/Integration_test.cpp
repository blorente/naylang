//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/Evaluator.h>
#include <model/evaluators/GraceEvaluator.h>
#include <model/environment/identifiers/IdentifierFactory.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Composite arithmetic operations", "[Integration Tests]") {
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
    auto assignX = std::make_shared<Assignment>(declareX, minusSeven);

    // Not evaluated directly
    auto refY = std::make_shared<VariableReference>("y");
    auto refX = std::make_shared<VariableReference>(declareX);
    auto yTimesX = std::make_shared<Multiplication>(refY, refX);

    auto reassignX = std::make_shared<Assignment>(declareX, yTimesX);

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
    auto xReference = std::make_shared<VariableReference>(xDeclaration);
    auto yReference = std::make_shared<VariableReference>(yDeclaration);

    auto tru = std::make_shared<Boolean>(true);
    auto fals = std::make_shared<Boolean>(false);
    auto one = std::make_shared<Number>(1.0);
    auto zero = std::make_shared<Number>(0.0);
    auto five = std::make_shared<Number>(5.0);
    auto six = std::make_shared<Number>(6.0);

    // x=5; y=6;
    auto xEqualsFive = std::make_shared<Assignment>(xDeclaration, five);
    auto yEqualsSix = std::make_shared<Assignment>(yDeclaration, six);

    // if (true) { x=x+1; }
    auto ITE1ThenBlock = std::make_shared<ExpressionBlock>();
    auto xPlusOne = std::make_shared<Addition>(xReference, one);
    auto xEqualsXPlusOne = std::make_shared<Assignment>(xDeclaration, xPlusOne);
    ITE1ThenBlock->addInstruction(xEqualsXPlusOne);

    // else { y=0; }
    auto ITE1ElseBlock = std::make_shared<ExpressionBlock>();
    auto yEqualsZero = std::make_shared<Assignment>(yDeclaration, zero);
    ITE1ElseBlock->addInstruction(yEqualsZero);

    auto ITE1 = std::make_shared<IfThenElse>(tru, ITE1ThenBlock, ITE1ElseBlock);

    // y = y+1;
    auto yPlusOne = std::make_shared<Addition>(yReference, one);
    auto yEqualsYPlusOne = std::make_shared<Assignment>(yDeclaration, yPlusOne);

    // if (false) { x=0; }
    auto ITE2ThenBlock = std::make_shared<ExpressionBlock>();
    auto xEqualsZero = std::make_shared<Assignment>(xDeclaration, zero);
    ITE2ThenBlock->addInstruction(xEqualsZero);

    // else { x=y+1; y=y+1; }
    auto ITE2ElseBlock = std::make_shared<ExpressionBlock>();
    auto xEqualsYPlusOne = std::make_shared<Assignment>(xDeclaration, yPlusOne);
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

TEST_CASE("Method calls and definitions with assignments and boolean operators", "[Integration Tests]") {
    /*
    method add(a)to(b)if_not(c) {
        if(!c) {
            return a + b;
        } else {
            return b;
        }
    }
    t = true;
    f = false;
    base = 5;
    x = add(3)to(base)if_not(f);
    y = add(2)to(base)if_not(t);
    require(x == 8);
    require(y == 5);
     */

    GraceEvaluator evaluator;
    auto xDeclaration = std::make_shared<VariableDeclaration>("x");
    auto yDeclaration = std::make_shared<VariableDeclaration>("y");
    auto baseDeclaration = std::make_shared<VariableDeclaration>("base");
    auto tDeclaration = std::make_shared<VariableDeclaration>("t");
    auto fDeclaration = std::make_shared<VariableDeclaration>("f");

    auto xReference = std::make_shared<VariableReference>(xDeclaration);
    auto yReference = std::make_shared<VariableReference>(yDeclaration);
    auto baseReference = std::make_shared<VariableReference>(baseDeclaration);
    auto tReference = std::make_shared<VariableReference>(tDeclaration);
    auto fReference = std::make_shared<VariableReference>(fDeclaration);

    auto tru = std::make_shared<Boolean>(true);
    auto fals = std::make_shared<Boolean>(false);

    auto five = std::make_shared<Number>(5.0);
    auto three = std::make_shared<Number>(3.0);
    auto two = std::make_shared<Number>(2.0);

    // method add(a)to(b)if_not(c) {
    std::vector<std::string> identifierNames = {"add", "to", "if_not"};
    std::vector<int> identifierParams = {1, 1, 1};
    auto methodIdentifier = IdentifierFactory::createMethodIdentifier(identifierNames, identifierParams);

    auto aDeclaration = std::make_shared<VariableDeclaration>("a");
    auto bDeclaration = std::make_shared<VariableDeclaration>("b");
    auto cDeclaration = std::make_shared<VariableDeclaration>("c");
    auto aReference = std::make_shared<VariableReference>(aDeclaration);
    auto bReference = std::make_shared<VariableReference>(bDeclaration);
    auto cReference = std::make_shared<VariableReference>(cDeclaration);
    auto paramVector = {aDeclaration, bDeclaration, cDeclaration};
    auto methodParams = std::make_shared<ParameterList>(paramVector);

    auto methodBody = std::make_shared<ExpressionBlock>();
    // if(!c) {
    auto ITECondition = std::make_shared<BooleanNot>(cReference);
    // return a + b;
    auto ITEThenBlock = std::make_shared<ExpressionBlock>();
    auto aPlusB = std::make_shared<Addition>(aReference, bReference);
    ITEThenBlock->addInstruction(aPlusB);
    // } else {
    auto ITEElseBlock = std::make_shared<ExpressionBlock>();
    // return b;
    ITEElseBlock->addInstruction(bReference);
    // }
    auto ITEExpression = std::make_shared<IfThenElse>(ITECondition, ITEThenBlock, ITEElseBlock);
    methodBody->addInstruction(ITEExpression);

    auto methodDeclaration = std::make_shared<MethodDeclaration>(methodIdentifier, methodParams, methodBody);

    // t = true;
    auto tToTrue = std::make_shared<Assignment>(tDeclaration, tru);
    // f = false;
    auto fToFalse = std::make_shared<Assignment>(fDeclaration, fals);
    // base = 5;
    auto baseToFive = std::make_shared<Assignment>(baseDeclaration, five);
    // x = add(3)to(base)if_not(f);
    auto xCallParam1 = std::make_shared<Assignment>(aDeclaration, three);
    auto xCallParam2 = std::make_shared<Assignment>(bDeclaration, baseReference);
    auto xCallParam3 = std::make_shared<Assignment>(cDeclaration, fReference);
    auto xCallParams = {xCallParam1, xCallParam2, xCallParam3};
    auto xCall = std::make_shared<MethodCall>(methodDeclaration, xCallParams);
    auto xToCall = std::make_shared<Assignment>(xDeclaration, xCall);
    // y = add(2)to(base)if_not(t);
    auto yCallParam1 = std::make_shared<Assignment>(aDeclaration, two);
    auto yCallParam2 = std::make_shared<Assignment>(bDeclaration, baseReference);
    auto yCallParam3 = std::make_shared<Assignment>(cDeclaration, tReference);
    auto yCallParams = {yCallParam1, yCallParam2, yCallParam3};
    auto yCall = std::make_shared<MethodCall>(methodDeclaration, yCallParams);
    auto yToCall = std::make_shared<Assignment>(yDeclaration, yCall);

    // Create program block
    evaluator.evaluate(*methodDeclaration);
    evaluator.evaluate(*tDeclaration);
    evaluator.evaluate(*tToTrue);
    evaluator.evaluate(*fDeclaration);
    evaluator.evaluate(*fToFalse);
    evaluator.evaluate(*baseDeclaration);
    evaluator.evaluate(*baseToFive);
    evaluator.evaluate(*xDeclaration);
    evaluator.evaluate(*xToCall);
    evaluator.evaluate(*yDeclaration);
    evaluator.evaluate(*yToCall);

    // require(x == 8);
    evaluator.evaluate(*xReference);
    REQUIRE(evaluator.getPartialDouble() == 8.0);
    // require(y == 5);
    evaluator.evaluate(*yReference);
    REQUIRE(evaluator.getPartialDouble() == 5.0);
}
