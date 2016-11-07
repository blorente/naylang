#include <implementations/operations/ArithmeticOperation.h>
#include "catch.h"
#include "implementations/expressions/ExpBoolean.h"

using namespace naylang;

TEST_CASE("A Boolean expression returns a Boolean", "[ExpBoolean]") {
    SECTION("ExpBoolean can take a Boolean (trivial case)") {
        Boolean truthy(true), falsy(false);
        ExpBoolean truth(truthy), lie(falsy);
        REQUIRE(truth.evaluate().value());
        REQUIRE(!lie.evaluate().value());
    }
}
