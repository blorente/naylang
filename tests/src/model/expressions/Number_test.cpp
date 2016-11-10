#include "catch.h"
#include <model/expressions/Number.h>

using namespace naylang;

TEST_CASE("Numbers hold constant primitive values", "[Number]") {
    Number number = Number(5.0);
    REQUIRE(number == Number(5.0));
}
