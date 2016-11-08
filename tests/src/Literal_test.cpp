#include "catch.h"
#include "implementations/expressions/ExpLiteral.h"

using namespace naylang;

TEST_CASE("A Literal can be a double", "[Literal]") {
    Literal<double> l = Literal<double>(3.0);
    REQUIRE(l.evaluate() == 3.0);
}

TEST_CASE("A Number is a Literal<double>", "[Literal]") {
    Number num = Number(3.0);
    REQUIRE(num.evaluate() == 3.0);
}
