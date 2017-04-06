//
// Copyright (c) 1/5/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/declarations/MethodDeclaration.h>
#include <model/ast/declarations/VariableDeclaration.h>
#include <model/ast/NodeFactory.h>
#include "catch.h"


using namespace naylang;

TEST_CASE("Method Declaration", "[Declarations]") {
    auto paramDecl = make_node<VariableDeclaration>("x");
    auto paramRef = make_node<ImplicitRequestNode>("x");

    std::vector<DeclarationPtr> parameters{paramDecl};
    std::vector<StatementPtr> body{paramRef};

    SECTION("A Method Declaration takes a canonicalName, a list of parameters and a body") {
        MethodDeclaration parameterlessEmptyMethod("myMethod", {}, {});
    }

    SECTION("A Method Declaration can return it's name, parameters and body") {
        MethodDeclaration oneParameterMethod("myMethod(_)", parameters, body);
        REQUIRE(oneParameterMethod.name() == "myMethod(_)");
        REQUIRE(std::equal(parameters.begin(), parameters.end(), oneParameterMethod.params().begin()));
        REQUIRE(std::equal(body.begin(), body.end(), oneParameterMethod.body().begin()));
    }

}