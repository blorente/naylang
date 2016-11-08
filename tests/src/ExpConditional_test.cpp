#include <implementations/operations/ArithmeticOperation.h>
#include <implementations/expressions/ExpBoolean.h>
#include <implementations/expressions/ExpArithmetic.h>
#include "catch.h"
#include "implementations/expressions/ExpConditional.h"

using namespace naylang;

TEST_CASE("A conditional takes two expressions of the same type, and one bool", "[ExpConditional]") {
    Number one(1.0), two(2.0);
    Boolean truth(true), lie(false);
    ExpBoolean condition_true(truth);
    ExpBoolean condition_false(lie);
    ArithmeticOperation sum(ArithmeticOperator::ADD);
    ArithmeticOperation sub(ArithmeticOperator::SUB);

    SECTION("ExpConditional can return a number") {
        ExpArithmetic pos_example(one, sum, two);
        ExpArithmetic neg_example(one, sub, two);

        ExpConditional<Number> positive(condition_true, pos_example, neg_example);
        REQUIRE(positive.evaluate() == Number(3.0));

        ExpConditional<Number> negative(condition_false, pos_example, neg_example);
        REQUIRE(negative.evaluate() == Number(-1.0));
    }
}
