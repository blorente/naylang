#include <implementations/operations/ArithmeticOperation.h>
#include "catch.h"
#include "implementations/expressions/ExpArithmetic.h"

using namespace naylang;

TEST_CASE("An arithmetic expression accepts two Numbers and a BinaryOperation", "[ExpArithmetic]") {
    ArithmeticOperation sum = ArithmeticOperation(ArithmeticOperator::ADD);
    Number two(2.0);
    Number threePointFive(3.5);
    ExpArithmetic expr = ExpArithmetic(two, sum, threePointFive);
    REQUIRE(expr.evaluate() == Number(5.5));

    SECTION("Arithmetic expressions can be nested", "[ExpArithmetic]") {
        ArithmeticOperation sum = ArithmeticOperation(ArithmeticOperator::ADD);
        ArithmeticOperation mul = ArithmeticOperation(ArithmeticOperator::MUL);
        Number two(2.0);
        Number minusThree(-3.0);
        Number one(1.0);
        ExpArithmetic firstSum = ExpArithmetic(two, sum, minusThree);
        REQUIRE(firstSum.evaluate().value() == -1.0);
        ExpArithmetic secondSum = ExpArithmetic(two, sum, one);
        REQUIRE(secondSum.evaluate().value() == 3.0);
        ExpArithmetic composedMul = ExpArithmetic(firstSum, mul, secondSum);
        REQUIRE(composedMul.evaluate().value() == -3.0);
    }
}

