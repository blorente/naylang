//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/ast/control/Return.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Return statements", "[Control]") {
    SECTION("A return statement takes no parameters") {
        Return ret;
    }
}