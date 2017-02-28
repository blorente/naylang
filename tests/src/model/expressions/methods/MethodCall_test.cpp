//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <model/expressions/methods/MethodCall.h>
#include <model/expressions/primitives/Number.h>
#include <model/environment/identifiers/IdentifierFactory.h>
#include <model/statements/VariableDeclaration.h>
#include <model/statements/methods/ParameterList.h>
#include <model/statements/Assignment.h>

using namespace naylang;

TEST_CASE("Method Calls", "[Expressions]") {
    auto zero = std::make_shared<Number>(0.0);
    auto name = IdentifierFactory::createMethodIdentifier("myMethod", 0);
    auto emptyParameters = std::make_shared<ParameterList>();

    auto xDeclaration = std::make_shared<VariableDeclaration>("x");
    std::vector<std::shared_ptr<VariableDeclaration>> shortParams{xDeclaration};
    auto oneParameter = std::make_shared<ParameterList>(shortParams);

    auto body = std::make_shared<ExpressionBlock>();

    auto declarationNoParams = std::make_shared<MethodDeclaration>(name, emptyParameters, body);
    auto declarationOneParam = std::make_shared<MethodDeclaration>(name, oneParameter, body);

    auto xEqualsZero = std::make_shared<Assignment>(xDeclaration, zero);

    SECTION("A method call needs a reference to a MethodDeclaration") {
        MethodCall call(declarationNoParams);
    }

    SECTION("A method call can contain a parameter assignment list") {
        MethodCall call(declarationOneParam, {xEqualsZero});
    }

    SECTION("A method call returns it's declaration, name and bindings") {
        MethodCall call(declarationOneParam, {xEqualsZero});
        REQUIRE(call.declaration() == declarationOneParam);
        REQUIRE(call.getMethodName() == name);
        REQUIRE(call.getParameters().size() == 1);
        REQUIRE(call.getParameters()[0] == xEqualsZero);
    }
}