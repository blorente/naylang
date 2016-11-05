#include <implementations/operations/OpSum.h>
#include "catch.h"
#include "implementations/expressions/ExpArithmetic.h"

using namespace naylang;

TEST_CASE("An arithmetic expression accepts two Numbers and a BinaryOperation", "[ExpArithmetic]") {
    OpSum sum = OpSum();
    Number two(2.0);
    Number threePointFive(3.5);
    ExpArithmetic expr = ExpArithmetic(two, sum, threePointFive);
    REQUIRE(expr.evaluate() == Number(5.5));
}