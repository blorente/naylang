//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/execution/objects/GraceClosure.h>
#include <model/ast/NodeFactory.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Grace Closure", "[GraceObjects]") {

    SECTION("A Closure accepts a method to enclose as parameter") {
        MethodPtr meth = make_meth(make_node<Block>());
        GraceClosure closure(meth);
    }
}