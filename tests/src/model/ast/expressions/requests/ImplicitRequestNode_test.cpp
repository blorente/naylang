//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/ast/expressions/requests/ImplicitRequestNode.h>
#include <model/ast/declarations/VariableDeclaration.h>
#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/NodeFactory.h>

using namespace naylang;

TEST_CASE("ImplicitRequestNode Expressions", "[Requests]") {

    auto five = make_node<NumberLiteral>(5.0);
    auto xDecl = make_node<VariableDeclaration>("x");
    std::vector<DeclarationPtr> params{xDecl};
    std::vector<StatementPtr> lines{};
    auto emptyOneParamMethod = make_node<MethodDeclaration>("myMethod", params, lines);

    SECTION("A ImplicitRequestNode has a target identifier name, parameter expressions and no reciever") {
        REQUIRE_NOTHROW(ImplicitRequestNode req("myMethod", {five}););
    }

    SECTION("An ImplicitRequestNode with an empty parameter list can request variable values or parametereless methods") {
        REQUIRE_NOTHROW(ImplicitRequestNode variableReq("x"););
        REQUIRE_NOTHROW(ImplicitRequestNode methodReq("myMethod"););
    }

    SECTION("A ImplicitRequestNode can return the identifier name and parameter expressions") {
        ImplicitRequestNode req("myMethod", {five});
        REQUIRE(req.identifier() == "myMethod");
        REQUIRE(req.params() == std::vector<ExpressionPtr>{five});
    }

    SECTION("A ImplicitRequestNode can be bound to a identifier declaration") {
        ImplicitRequestNode req("myMethod", {five});
        req.bindTo(*emptyOneParamMethod);

        REQUIRE(req.declaration() == emptyOneParamMethod.get());
    }
}


