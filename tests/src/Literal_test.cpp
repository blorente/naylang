#include "catch.h"
#include "definitions/Literal.h"

using namespace naylang;

TEST_CASE("A Literal can be a double", "[Literal]") {
    Literal<double> l = Literal<double>(3.0);
    REQUIRE(l.value() == 3.0);
}

TEST_CASE("A Number is a Literal<double>", "[Literal]") {
    Number num = Number(3.0);
    REQUIRE(num.value() == 3.0);
}
