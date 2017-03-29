//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <model/execution/objects/GraceIterable.h>
#include <model/execution/objects/GraceNumber.h>
#include <model/execution/objects/GraceString.h>
#include <model/execution/objects/GraceBlock.h>
#include <model/execution/objects/GraceBoolean.h>

#include <model/ast/declarations/VariableDeclaration.h>
#include <model/ast/expressions/VariableReference.h>
#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/expressions/requests/ExplicitRequestNode.h>

#include "catch.h"

using namespace naylang;

TEST_CASE("Grace Iterables", "[GraceObjects]") {
    auto five = make_obj<GraceNumber>(5.0);
    auto six = make_obj<GraceNumber>(6.0);
    auto hello = make_obj<GraceString>("hello");
    auto tru = make_obj<GraceBoolean>(true);

    SECTION("The constructor takes al list of elements") {
        REQUIRE_NOTHROW(GraceIterable iter({five, hello, tru, six}););
    }

    SECTION("A Grace Iterable can return it's values") {
        GraceIterable iter({five, hello, tru, six});
        std::vector<GraceObjectPtr> expected{five, hello, tru, six};
        REQUIRE(std::equal(expected.begin(), expected.end(), iter.values().begin()));
    }

    SECTION("A GraceIterable can chang it's elements with the index") {
        GraceIterable iter({five, six});
        iter.setElem(1, five);
        std::vector<GraceObjectPtr> expected{five, five};
        REQUIRE(std::equal(expected.begin(), expected.end(), iter.values().begin()));
    }
}

TEST_CASE("Grace Iterables Native methods", "[GraceIterable]") {
    auto five = make_obj<GraceNumber>(5.0);
    auto six = make_obj<GraceNumber>(6.0);
    auto hello = make_obj<GraceString>("hello");
    auto tru = make_obj<GraceBoolean>(true);

    GraceIterable::Append plusPlus;
    GraceIterable::Do myDo;

    SECTION("++(_) appends an object to the contents") {
        GraceIterable list({five, hello, six});
        MethodRequest concat("++(_)", {tru});
        plusPlus.respond(list, concat);
        REQUIRE(*GraceTrue == *list.values()[3]);
    }

    SECTION("do(_) executes a block on each parameter") {
        auto one = make_node<NumberLiteral>(1.0);
        auto paramRef = make_node<VariableReference>("x");
        auto paramDecl = make_node<VariableDeclaration>("x");
        std::vector<ExpressionPtr> oneBlock{one};
        auto add = make_node<ExplicitRequestNode>("+(_)", paramRef, oneBlock);

        std::vector<DeclarationPtr> params{paramDecl};
        std::vector<StatementPtr> body{add};
        auto meth = make_meth(params, body);
        auto block = make_obj<GraceBlock>(meth);

        MethodRequest req("do(_)", {block});
        ExecutionEvaluator eval;
        GraceIterable lineup({five, six});

        REQUIRE_NOTHROW(myDo.respond(eval, lineup, req));
        REQUIRE(lineup.values()[0]->asNumber().value() == 6.0);
        REQUIRE(lineup.values()[1]->asNumber().value() == 7.0);

        REQUIRE_NOTHROW(myDo.respond(eval, lineup, req));
        REQUIRE(lineup.values()[0]->asNumber().value() == 7.0);
        REQUIRE(lineup.values()[1]->asNumber().value() == 8.0);
    }
}