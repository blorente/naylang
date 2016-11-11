#include "catch.h"
#include <model/Environment.h>

using namespace naylang;

TEST_CASE("An Environment can store (string, Expression *) pairs", "[Environment]") {
    Environment root;
    SECTION("An Environment is initially empty") {
        //REQUIRE(root.isEmpty());
    }
}
