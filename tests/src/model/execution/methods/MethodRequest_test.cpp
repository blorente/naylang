//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/execution/methods/MethodRequest.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Method Request", "[Methods]") {
    SECTION("A method request accepts a name") {
        MethodRequest req("prefix!");
    }
}