#include "catch.h"
#include <implementations/operations/ArithmeticOperation.h>
#include <implementations/expressions/ExpArithmetic.h>
#include <implementations/statements/ConditionalStatement.h>

using namespace naylang;
/*
TEST_CASE("A conditional takes two expressions of the same type, and one bool", "[ConditionalStatement]") {
    Number one(1.0), two(2.0);
    Boolean condition_true(true), condition_false(false);
    ArithmeticOperation sum(ArithmeticOperator::ADD);
    ArithmeticOperation sub(ArithmeticOperator::SUB);

    SECTION("ExpConditional can return a number") {
        ExpArithmetic pos_example(one, sum, two);
        ExpArithmetic neg_example(one, sub, two);

        ConditionalStatement positive(condition_true, pos_example, neg_example);
        ConditionalStatement negative(condition_false, pos_example, neg_example);
    }
}
 */
