//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <iostream>
#include <model/environment/identifiers/IdentifierFactory.h>
#include <model/statements/control/WhileLoop.h>
#include <model/statements/methods/ParameterList.h>
#include "catch.h"

#include "model/evaluators/GraceEvaluator.h"

using namespace naylang;

TEST_CASE("Grace Evaluator", "[Evaluators]") {
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

    auto xDeclaration = std::make_shared<VariableDeclaration>("x");

    auto xRef = std::make_shared<VariableReference>(xDeclaration);
    auto xRefBlock = std::make_shared<ExpressionBlock>(); xRefBlock->addInstruction(xRef);

    SECTION("A Number expression just stores the asNumber") {
        GraceEvaluator eval;
        Number fiveNat(5.0);
        REQUIRE_NOTHROW(eval.evaluate(fiveNat));
        REQUIRE(eval.getPartialDouble() == fiveNat.value());
    }

    SECTION("If the canonName of a constant already exists in the environment, it throws an exception") {
        GraceEvaluator eval;
        Constant xConstant("x", six);
        REQUIRE_NOTHROW(eval.evaluate(xConstant));
        REQUIRE_THROWS(eval.evaluate(xConstant));
    }

    SECTION("A variable declaration must be made before an assignment can be done") {
        GraceEvaluator eval;
        Assignment xAssignment(xDeclaration, six);
        REQUIRE_THROWS(eval.evaluate(xAssignment));
        REQUIRE_NOTHROW(eval.evaluate(*xDeclaration));
        REQUIRE_NOTHROW(eval.evaluate(xAssignment));
    }

    SECTION("A variable reference throws if the value is invalid (not initialized)") {
        GraceEvaluator eval;

        VariableReference xReference(xDeclaration);
        REQUIRE_NOTHROW(eval.evaluate(*xDeclaration));
        REQUIRE_THROWS(eval.evaluate(xReference));
    }

    SECTION("A variable reference places the asNumber in the partial") {
        GraceEvaluator eval;
        VariableReference xReference(xDeclaration);
        Assignment xAssignment(xDeclaration, six);
        REQUIRE_NOTHROW(eval.evaluate(*xDeclaration));
        REQUIRE_NOTHROW(eval.evaluate(xAssignment));
        REQUIRE_NOTHROW(eval.evaluate(xReference));
        REQUIRE(eval.getPartialDouble() == 6.0);
    }

    SECTION("The evaluator throws an exception when dividing by 0") {
        GraceEvaluator eval;
        Division divideByZero(six, zero);
        REQUIRE_THROWS(eval.evaluate(divideByZero));
    }

    SECTION("The evaluator places the asNumber of a Boolean in a partial") {
        GraceEvaluator eval;
        REQUIRE_NOTHROW(eval.evaluate(*tru));
        REQUIRE(eval.getPartialBool());
    }

    SECTION("The evaluator executes ITE blocks according to the condition") {
        GraceEvaluator eval;
        IfThenElse iteSix(tru, sixBlock, zeroBlock);
        IfThenElse iteZero(fals, sixBlock, zeroBlock);
        REQUIRE_NOTHROW(eval.evaluate(iteSix));
        REQUIRE(eval.getPartialDouble() == 6.0);
        REQUIRE_NOTHROW(eval.evaluate(iteZero));
        REQUIRE(eval.getPartialDouble() == 0.0);
    }

    SECTION("The evaluator evaluates expresions in a block sequenatially") {
        GraceEvaluator eval;
        auto xAssignment = std::make_shared<Assignment>(xDeclaration, six);
        auto xReference = std::make_shared<VariableReference>(xDeclaration);

        ExpressionBlock block;
        block.addInstruction(xDeclaration);
        block.addInstruction(xAssignment);
        block.addInstruction(xReference);

        REQUIRE_NOTHROW(eval.evaluate(block));
        REQUIRE(eval.getPartialDouble() == 6.0);
    }

    SECTION("Evaluating a method declaration adds it to the environment") {
        GraceEvaluator eval;
        auto id = IdentifierFactory::createMethodIdentifier("myMethod", 0);
        auto methodBody = std::make_shared<ExpressionBlock>();
        methodBody->addInstruction(zero);
        MethodDeclaration method(std::move(id), methodBody);

        REQUIRE_NOTHROW(eval.evaluate(method));
    }

    SECTION("Evaluating an undeclared method throws") {
        GraceEvaluator eval;
        auto id = IdentifierFactory::createMethodIdentifier("nonExistent", 0);
        MethodCall wrongCall(std::move(id));

        REQUIRE_THROWS(eval.evaluate(wrongCall));
    }

    SECTION("Evaluating a declared method without void parameters executes it's block") {
        GraceEvaluator eval;
        auto id = IdentifierFactory::createMethodIdentifier("myMethod", 0);
        auto methodBody = std::make_shared<ExpressionBlock>();
        methodBody->addInstruction(five);
        MethodDeclaration method(id, methodBody);
        MethodCall rightCall(id);

        REQUIRE_NOTHROW(eval.evaluate(method));
        REQUIRE_NOTHROW(eval.evaluate(rightCall));
        REQUIRE(eval.getPartialDouble() == 5.0);
    }

    SECTION("Evaluating a method call with parameters stores the values in a new environment") {
        GraceEvaluator eval;
        std::vector<std::string> words {"myMethod", "parameters"};
        std::vector<int> params {0, 0};
        auto declarationId = IdentifierFactory::createMethodIdentifier(words, params);
        auto callId = IdentifierFactory::createMethodIdentifier(declarationId);

        auto tempDecl = std::make_shared<VariableDeclaration>("temp0");

        auto tempRef = std::make_shared<VariableReference>(tempDecl);

        auto tempRefBlock = std::make_shared<ExpressionBlock>(); tempRefBlock->addInstruction(tempRef);

        MethodDeclaration method(declarationId, tempRefBlock);
        MethodCall parameterCall(callId, {five});

        REQUIRE_NOTHROW(eval.evaluate(method));
        REQUIRE_NOTHROW(eval.evaluate(parameterCall));
        REQUIRE(eval.getPartialDouble() == 5.0);
    }

    SECTION("Evaluating a while loop evaluates the body while condition is true") {
        GraceEvaluator eval;
        auto condDeclaration = std::make_shared<VariableDeclaration>("cond");
        auto condReference = std::make_shared<VariableReference>(condDeclaration);
        auto setCondToTrue = std::make_shared<Assignment>(condDeclaration, tru);
        auto setCondToFalse = std::make_shared<Assignment>(condDeclaration, fals);

        auto pushFiveAndCondFalse = std::make_shared<ExpressionBlock>();
        pushFiveAndCondFalse->addInstruction(five);
        pushFiveAndCondFalse->addInstruction(setCondToFalse);

        WhileLoop getFive(condReference, pushFiveAndCondFalse);

        /*
         * cond = true;
         * while(cond) {
         *  5;
         *  cond = false;
         * }
         */

        REQUIRE_NOTHROW(eval.evaluate(*condDeclaration));
        REQUIRE_NOTHROW(eval.evaluate(*setCondToTrue));
        REQUIRE_NOTHROW(eval.evaluate(getFive));
        REQUIRE(eval.getPartialDouble() == 5.0);
    }

    SECTION("Evaluating a parameter list declares the variables in the environment") {
        GraceEvaluator eval;
        ParameterList xParams({xDeclaration});
        Assignment xToFive(xDeclaration, five);

        REQUIRE_NOTHROW(eval.evaluate(xParams));
        REQUIRE_NOTHROW(eval.evaluate(xToFive));
        REQUIRE_NOTHROW(eval.evaluate(*xRef));
        REQUIRE(eval.getPartialDouble() == 5.0);
    }
}