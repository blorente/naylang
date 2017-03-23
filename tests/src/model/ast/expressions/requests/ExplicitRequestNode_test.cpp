//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/ast/expressions/requests/ExplicitRequestNode.h>
#include <model/ast/NodeFactory.h>
#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/expressions/VariableReference.h>
#include <model/ast/declarations/VariableDeclaration.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Explicit Request Node expressions", "[Requests]") {

    auto five = make_node<NumberLiteral>(5.0);
    auto xDecl = make_node<VariableDeclaration>("x");
    auto recieverRef = make_node<VariableReference>("reciever");
    std::vector<DeclarationPtr> params{xDecl};
    std::vector<StatementPtr> lines;
    auto emptyOneParamMethod = make_node<MethodDeclaration>("myMethod", params, lines);

    SECTION("A ExplicitRequestNode has a target identifier name, a reciever and optionally a parameter list") {
        REQUIRE_NOTHROW(ExplicitRequestNode req("myMethod", recieverRef, {five}););
        REQUIRE_NOTHROW(ExplicitRequestNode req("myMethod", recieverRef););
    }

    SECTION("A ExplicitRequestNode can return the identifier name, receiver and parameter expressions") {
        ExplicitRequestNode req("myMethod", five, {five});
        REQUIRE(req.identifier() == "myMethod");
        REQUIRE(req.params() == std::vector<ExpressionPtr>{five});
        REQUIRE(req.receiver() == five);
    }

    SECTION("A ExplicitRequestNode can be bound to a identifier declaration") {
        ExplicitRequestNode req("myMethod", five, {five});
        req.bindTo(*emptyOneParamMethod);
        REQUIRE(&req.declaration() == emptyOneParamMethod.get());
    }
}