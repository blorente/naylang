//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/execution/methods/MethodRequest.h>
#include <core/model/execution/objects/GraceObject.h>
#include <core/model/execution/objects/GraceBoolean.h>
#include <core/model/execution/memory/Heap.h>
#include <core/model/evaluators/ExecutionEvaluator.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Method ImplicitRequestNode", "[Methods]") {
    ExecutionEvaluator ctx;

    SECTION("A method request accepts a name") {
        MethodRequest req("prefix!");
    }

    SECTION("A method request also accepts a list of parameters") {
        std::vector<GraceObjectPtr> params;
        params = {GraceTrue, ctx.create_obj<GraceBoolean>(false)};
        MethodRequest req("prefix!", params);
    }

    SECTION("A method request can return it's name and list of parameters") {
        std::vector<GraceObjectPtr> params{GraceTrue, ctx.create_obj<GraceBoolean>(false)};
        MethodRequest req("prefix!", params);

        REQUIRE(req.name() == "prefix!");
        REQUIRE(std::equal(params.begin(), params.end(), req.params().begin()));
    }
}