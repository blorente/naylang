//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/execution/objects/UserObject.h>
#include <core/model/execution/objects/GraceNumber.h>
#include <core/model/ast/NodeFactory.h>
#include <core/model/execution/methods/MethodFactory.h>
#include <core/model/execution/memory/Heap.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Grace User-defined object", "[GraceObjects]") {
    UserObject obj;
}

TEST_CASE("UserObject common utils", "[UserObject]") {
    Heap heap;
    SECTION("Calling prettyPrint on a UserObject a list of the fields and userMethods in brackets") {
        UserObject usr;
        usr.setField("x", heap.make_obj<GraceNumber>(5.0));
        auto param = make_node<VariableDeclaration>("n");
        std::vector<DeclarationPtr> params{param};
        std::vector<StatementPtr> body{};
        usr.addMethod("hi(_)", make_meth(params, body));
        REQUIRE(usr.prettyPrint(0) == "object {\n  x = 5.000000\n  method hi(n) { }\n}");
    }
}