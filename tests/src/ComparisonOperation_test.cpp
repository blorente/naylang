#include "catch.h"
#include "definitions/Literal.h"
#include "implementations/operations/ComparisonOperation.h"

using namespace naylang;

TEST_CASE("Comparison operations can deal with Number", "[ComparisonOperation]") {
    Number one(1.0), two(2.0), three(3.0);
    Number anotherOne(1.0);
    ComparisonOperation equals(ComparisonOperator::EQUAL);
    ComparisonOperation notEquals(ComparisonOperator::NOT_EQUAL);
    ComparisonOperation greater(ComparisonOperator::GREATER);
    ComparisonOperation greaterOrEqual(ComparisonOperator::GREATER_OR_EQUAL);
    ComparisonOperation smaller(ComparisonOperator::SMALLER);
    ComparisonOperation smallerOrEqual(ComparisonOperator::SMALLER_OR_EQUAL);

    REQUIRE(equals.operate(one, anotherOne).value());
    REQUIRE(notEquals.operate(one, two).value());

    REQUIRE(!greater.operate(one, three).value());
    REQUIRE(greater.operate(three, one).value());

    REQUIRE(!greaterOrEqual.operate(one, three).value());
    REQUIRE(greaterOrEqual.operate(three, one).value());
    REQUIRE(greaterOrEqual.operate(one, anotherOne).value());

    REQUIRE(smaller.operate(one, three).value());
    REQUIRE(!smaller.operate(three, one).value());

    REQUIRE(smallerOrEqual.operate(one, three).value());
    REQUIRE(!smallerOrEqual.operate(three, one).value());
    REQUIRE(smallerOrEqual.operate(one, anotherOne).value());
}