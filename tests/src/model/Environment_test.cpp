#include "catch.h"
#include <model/Environment.h>
#include <model/Expression.h>
#include <model/expressions/Number.h>

using namespace naylang;

TEST_CASE("An Environment can store (string, std::unique_ptr<Expression>) pairs", "[Environment]") {
    Environment root;
    SECTION("An Environment is initially empty") {
        REQUIRE(root.isEmpty());
    }

    SECTION("An Environment stores (std::string, std::unique_ptr<Expression>) pairs") {
        std::string name("x");
        std::unique_ptr<Expression> number(new Number(5.0));

        root.insert(name, std::move(number));
        REQUIRE(static_cast<const Number &>(root.get(name)) == Number(5.0));
    }
}
