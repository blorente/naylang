#include "catch.h"
#include <model/expressions/Constant.h>
#include <model/expressions/Number.h>

#include <iostream>

using namespace naylang;

TEST_CASE("Constants return expressions", "[Constant]") {
    Number five(5.0);
    std::unique_ptr<Expression> five_ptr(new Number(5.0));
    Constant number("x", std::move(five_ptr));
    auto val = static_cast<const Number &>(number.value());
    REQUIRE(val == Number(5.0));
}
