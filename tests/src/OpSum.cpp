#include "catch.h"
#include "definitions/Literal.h"
#include "implementations/operations/OpSum.h"

using namespace naylang;

TEST_CASE("The sum operation takes two Numbers and returns a Number", "[OpSum]") {
    Number two(2.0);
    Number threePointFive(3.5);
    OpSum operation = OpSum();
    REQUIRE(operation.operate(two, threePointFive) == Number(5.5));
    REQUIRE(operation.operate(two, threePointFive).value() == 5.5);
}
