#include "catch.h"
#include "implementations/expressions/ExpLiteral.h"
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

    REQUIRE(equals.operate(one, anotherOne) == Boolean(true));
    REQUIRE(notEquals.operate(one, two) == Boolean(true));

    REQUIRE(greater.operate(one, three) == Boolean(false));
    REQUIRE(greater.operate(three, one) == Boolean(true));

    REQUIRE(greaterOrEqual.operate(one, three) == Boolean(false));
    REQUIRE(greaterOrEqual.operate(three, one) == Boolean(true));
    REQUIRE(greaterOrEqual.operate(one, anotherOne) == Boolean(true));

    REQUIRE(smaller.operate(one, three) == Boolean(true));
    REQUIRE(smaller.operate(three, one) == Boolean(false));

    REQUIRE(smallerOrEqual.operate(one, three) == Boolean(true));
    REQUIRE(smallerOrEqual.operate(three, one) == Boolean(false));
    REQUIRE(smallerOrEqual.operate(one, anotherOne) == Boolean(true));
}