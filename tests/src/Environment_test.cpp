#include "catch.h"
#include <implementations/Environment.h>
#include <definitions/Expression.h>
#include <implementations/expressions/ExpLiteral.h>

using namespace naylang;

TEST_CASE("An environment can hold (string, Expression) pairs", "[Environment]") {
    Environment env;
    REQUIRE(env.isEmpty());

    SECTION("Variables can be inserted and extracted") {
        ExpressionPointer five(new Number(5.0));
        env.insert("x", std::move(five));
        REQUIRE(env.get<Number>("x") == Number(5.0));
    }


}

