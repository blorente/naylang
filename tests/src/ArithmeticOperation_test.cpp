#include "catch.h"
#include "implementations/expressions/ExpLiteral.h"
#include "implementations/operations/ArithmeticOperation.h"

using namespace naylang;

TEST_CASE("The ADD operation takes two Numbers and returns a Number", "[ArithmeticOperation]") {
    Number five(5.0);
    Number threePointFive(3.5);
    ArithmeticOperation operation = ArithmeticOperation(ArithmeticOperator::ADD);
    REQUIRE(operation.operate(threePointFive, five) == Number(8.5));
}

TEST_CASE("The ADD operation can add negative numbers", "[ArithmeticOperation]") {
    Number minusTwo(-2.0);
    Number minusOne(-1.0);
    Number threePointFive(3.5);
    ArithmeticOperation operation = ArithmeticOperation(ArithmeticOperator::ADD);
    REQUIRE(operation.operate(minusTwo, threePointFive) == Number(1.5));
    REQUIRE(operation.operate(minusTwo, minusOne) == Number(-3.0));
}

TEST_CASE("ArithmeticOperation accepts SUBstraction", "[ArithmeticOperation]") {
    Number two(2.0);
    Number threePointFive(3.5);
    ArithmeticOperation operation = ArithmeticOperation(ArithmeticOperator::SUB);
    REQUIRE(operation.operate(threePointFive, two) == Number(1.5));
}

TEST_CASE("ArithmeticOperation accepts MULtiplication", "[ArithmeticOperation]") {
    Number two(2.0);
    Number zeroPointFive(0.5);
    Number minusOne(-1.0);
    ArithmeticOperation operation = ArithmeticOperation(ArithmeticOperator::MUL);
    SECTION("Halving positive and negative numbers") {
        REQUIRE(operation.operate(zeroPointFive, two) == Number(1.0));
        REQUIRE(operation.operate(zeroPointFive, minusOne) == Number(-0.5));
    }

    SECTION("Inverting the sign") {
        REQUIRE(operation.operate(zeroPointFive, minusOne) == Number(-0.5));
        REQUIRE(operation.operate(minusOne, minusOne) == Number(1.0));
    }
}

TEST_CASE("ArithmeticOperation accepts DIVision", "[ArithmeticOperation]") {
    Number two(2.0);
    Number three(3);
    Number minusOne(-1.0);
    Number zero(0.0);
    ArithmeticOperation operation = ArithmeticOperation(ArithmeticOperator::DIV);

    SECTION("Halving positive and negative numbers") {
        REQUIRE(operation.operate(three, two) == Number(1.5));
        REQUIRE(operation.operate(zero, two) == Number(0.0));
        REQUIRE(operation.operate(minusOne, two) == Number(-0.5));
    }

    SECTION("Division by 0 is inf") {
        REQUIRE_THROWS(operation.operate(three, zero) == Number(0.0));
    }
}
