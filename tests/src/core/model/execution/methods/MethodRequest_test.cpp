//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/execution/methods/MethodRequest.h>
#include <core/model/execution/objects/GraceObject.h>
#include <core/model/execution/objects/GraceBoolean.h>
#include <core/model/execution/memory/Heap.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Method ImplicitRequestNode", "[Methods]") {
    Heap heap;

    SECTION("A method request accepts a name") {
        MethodRequest req("prefix!");
    }

    SECTION("A method request also accepts a list of parameters") {
        std::vector<GraceObjectPtr> params;
        params = {GraceTrue, heap.make_obj<GraceBoolean>(false)};
        MethodRequest req("prefix!", params);
    }

    SECTION("A method request can return it's name and list of parameters") {
        std::vector<GraceObjectPtr> params{GraceTrue, heap.make_obj<GraceBoolean>(false)};
        MethodRequest req("prefix!", params);

        REQUIRE(req.name() == "prefix!");
        REQUIRE(std::equal(params.begin(), params.end(), req.params().begin()));
    }
}