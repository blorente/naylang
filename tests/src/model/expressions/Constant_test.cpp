#include "catch.h"
#include <model/expressions/Constant.h>
#include <model/expressions/Number.h>

#include <iostream>

using namespace naylang;

TEST_CASE("Constants return expressions", "[Constant]") {
	std::shared_ptr<Expression> five(new Number(5.0));
    Constant number("x", five);
    const Number &val = static_cast<const Number &>(number.value());
    REQUIRE(val == Number(5.0));
}
