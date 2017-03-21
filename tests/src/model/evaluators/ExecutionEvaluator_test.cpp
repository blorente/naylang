//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"
#include <model/evaluators/ExecutionEvaluator.h>
#include <model/ast/expressions/primitives/BooleanLiteral.h>
#include <model/ast/expressions/requests/ImplicitRequestNode.h>
#include <model/ast/expressions/requests/ExplicitRequestNode.h>
#include <model/ast/expressions/VariableReference.h>
#include <model/ast/declarations/Declaration.h>
#include <model/execution/objects/GraceBoolean.h>
#include <model/ast/control/Return.h>

using namespace naylang;

TEST_CASE("Execution Evaluator", "[Evaluators]") {

    SECTION("An execution evaluator has a partial GraceObject") {
        ExecutionEvaluator eval;
        REQUIRE(*make_obj<GraceDoneDef>() == *eval.partial());
    }

    SECTION("Particular nodes") {
        SECTION("Evaluating a BooleanLiteral expression places a GraceBoolean on the partial") {
            ExecutionEvaluator eval;
            BooleanLiteral tru(true);
            REQUIRE_NOTHROW(eval.evaluate(tru));
            REQUIRE(eval.partial()->asBoolean().value());
        }

        SECTION("Evaluating a Return node terminates the execution") {
            // It assumes that the last executed expression is in the partial
            ExecutionEvaluator eval;
            Return ret;
            REQUIRE_NOTHROW(eval.evaluate(ret));
        }

        SECTION("Evaluating a Block places a Closure on the partial, with an 'apply' method") {
            ExecutionEvaluator eval;
            auto blankBlock = make_node<Block>();
            blankBlock->accept(eval);
            REQUIRE(eval.partial()->isClosure());
        }
    }

    SECTION("Environment") {
        SECTION("The evaluator has a GraceScope environment object") {
            ExecutionEvaluator eval;
            REQUIRE(eval.currentScope()->isScope());
        }

        SECTION("An Execution Evaluator can create a scope") {
            ExecutionEvaluator eval;
            GraceObjectPtr newEnv = eval.createNewScope();
            REQUIRE(newEnv == eval.currentScope());
        }

        SECTION("An Execution Evaluator can restore a scope") {
            ExecutionEvaluator eval;
            GraceObjectPtr oldEnv = eval.currentScope();
            GraceObjectPtr newEnv = eval.createNewScope();
            eval.restoreScope();
            REQUIRE(oldEnv == eval.currentScope());
        }
    }

    SECTION("Native methods") {
        SECTION("Evaluating {!true} places GraceFalse on the partial") {
            ExecutionEvaluator eval;
            auto tru = make_node<BooleanLiteral>(true);
            auto prefNot = make_node<ExplicitRequestNode>("prefix!", tru);
            eval.evaluate(*prefNot);

            REQUIRE(*GraceFalse == *eval.partial());
        }

        SECTION("Evaluating {true && false} places GraceFalse on the partial") {
            ExecutionEvaluator eval;
            auto tru = make_node<BooleanLiteral>(true);
            auto fal = make_node<BooleanLiteral>(false);
            std::vector<ExpressionPtr> prefParams{fal};
            auto prefNot = make_node<ExplicitRequestNode>("&&(_)", tru, prefParams);
            eval.evaluate(*prefNot);

            REQUIRE(*GraceFalse == *eval.partial());
        }
    }

//    SECTION("Non-native methods") {
//        SECTION("Evaluating the user defined my&&(true, false) (logic AND) places GraceFalse on top of the stack") {
//            ExecutionEvaluator eval;
//            auto tru = make_node<VariableReference>("tru");
//            auto fal = make_node<VariableReference>("fal");
//            std::vector<ExpressionPtr> andParams{tru, fal};
//            auto andReq = make_node<ImplicitRequestNode>("&&(_)", andParams);
//            auto ret = make_node<Return>();
//            // self.my&&(other) == (self && other)
//            auto myAndBlock = make_node<Block>();
//            myAndBlock->addStatement(andReq);
//            myAndBlock->addStatement(ret);
//            auto myAndMeth = make_node<MethodDeclaration>("my&&(_)", myAndBlock);
//
//            auto trueLiteral = make_node<BooleanLiteral>(true);
//            auto falseLiteral = make_node<BooleanLiteral>(false);
//            std::vector<ExpressionPtr> requestParams{trueLiteral, falseLiteral};
//            auto myAndReq = make_node<ImplicitRequestNode>("my&&(_)", requestParams);
//
//            eval.evaluate(*myAndMeth);
//            eval.evaluate(*myAndReq);
//            REQUIRE(*GraceFalse == *eval.partial());
//        }
//    }
}