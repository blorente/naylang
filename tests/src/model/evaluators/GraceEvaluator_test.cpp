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
    auto fals = std::make_shared<Boolean>(false);

    auto zeroBlock = std::make_shared<ExpressionBlock>(); zeroBlock->addInstruction(zero);
    auto fiveBlock = std::make_shared<ExpressionBlock>(); fiveBlock->addInstruction(five);
    auto sixBlock = std::make_shared<ExpressionBlock>(); sixBlock->addInstruction(six);

    auto xRef = std::make_shared<VariableReference>("x");

    auto xRefBlock = std::make_shared<ExpressionBlock>(); xRefBlock->addInstruction(xRef);

    SECTION("A Number expression just stores the asNumber") {
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

    SECTION("A variable reference throws if the asNumber is invalid (not initialized)") {
        VariableDeclaration xDeclaration("x");
        VariableReference xReference("x");
        REQUIRE_NOTHROW(eval.evaluate(xDeclaration));
        REQUIRE_THROWS(eval.evaluate(xReference));
    }

    SECTION("A variable reference places the asNumber in the partial") {
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

    SECTION("The evaluator places the asNumber of a Boolean in a partial") {
        REQUIRE_NOTHROW(eval.evaluate(*tru));
        REQUIRE(eval.getPartialBool());
    }

    SECTION("The evaluator executes ITE blocks according to the condition") {
        IfThenElse iteSix(tru, sixBlock, zeroBlock);
        IfThenElse iteZero(fals, sixBlock, zeroBlock);
        REQUIRE_NOTHROW(eval.evaluate(iteSix));
        REQUIRE(eval.getPartialDouble() == 6.0);
        REQUIRE_NOTHROW(eval.evaluate(iteZero));
        REQUIRE(eval.getPartialDouble() == 0.0);
    }

    SECTION("The evaluator evaluates expresions in a block sequenatially") {
        auto xDeclaration = std::make_shared<VariableDeclaration>("x");
        auto xAssignment = std::make_shared<Assignment>("x", six);
        auto xReference = std::make_shared<VariableReference>("x");

        ExpressionBlock block;
        block.addInstruction(xDeclaration);
        block.addInstruction(xAssignment);
        block.addInstruction(xReference);

        REQUIRE_NOTHROW(eval.evaluate(block));
        REQUIRE(eval.getPartialDouble() == 6.0);
    }

    SECTION("Evaluating a method declaration adds it to the environment") {
        Identifier id{"myMethod"};
        auto methodBody = std::make_shared<ExpressionBlock>();
        methodBody->addInstruction(zero);
        MethodDeclaration method(id, methodBody);

        REQUIRE_NOTHROW(eval.evaluate(method));
    }

    SECTION("Evaluating an undeclared method throws") {
        Identifier id{"nonExistent"};
        MethodCall wrongCall(id);

        REQUIRE_THROWS(eval.evaluate(wrongCall));
    }

    SECTION("Evaluating a declared method without void parameters executes it's block") {
        Identifier id{"myMethod"};
        auto methodBody = std::make_shared<ExpressionBlock>();
        methodBody->addInstruction(five);
        MethodDeclaration method(id, methodBody);
        MethodCall rightCall(id);

        REQUIRE_NOTHROW(eval.evaluate(method));
        REQUIRE_NOTHROW(eval.evaluate(rightCall));
        REQUIRE(eval.getPartialDouble() == 5.0);
    }

    SECTION("Evaluating a method call with parameters stores the values in a new environment") {
        std::vector<std::string> words {"myMethod", "parameters"};
        Identifier id(words);

        auto tempRef = std::make_shared<VariableReference>("temp0");

        auto tempRefBlock = std::make_shared<ExpressionBlock>(); tempRefBlock->addInstruction(tempRef);

        MethodDeclaration method(id, tempRefBlock);
        MethodCall parameterCall(id, {five});

        REQUIRE_NOTHROW(eval.evaluate(method));
        REQUIRE_NOTHROW(eval.evaluate(parameterCall));
        REQUIRE(eval.getPartialDouble() == 5.0);
    }
}