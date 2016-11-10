#include "catch.h"
#include <model/expressions/Constant.h>
#include <model/expressions/Number.h>

using namespace naylang;

TEST_CASE("Constants return expressions", "[Constant]") {
    Constant number("x", Number(5.0));
    REQUIRE(dynamic_cast<const Number &>(number.value()) == Number(5.0));
}
