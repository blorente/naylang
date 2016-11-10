#include "catch.h"
#include <model/expressions/Number.h>

using namespace naylang;

TEST_CASE("NumberVisitors can access the value() of a Number", "[NumberVisitor]") {
    Number number = Number(5.0);
    NumberVisitor visitor;
    visitor.process(number);
}
