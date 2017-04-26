//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/ast/ASTNodeDefinitions.h>
#include <core/model/ast/NodeFactory.h>
#include "catch.h"

using namespace naylang;

TEST_CASE("Statements", "[AST]") {
    SECTION("Statements can contain code coordinates") {
        int lineNum = 0;
        int colNum = 1;
        StatementPtr node = make_node<StringLiteral>("Hello", lineNum, colNum);
        REQUIRE(node->line() == lineNum);
        REQUIRE(node->col() == colNum);
    }

    SECTION("Statements have coordinates (-1, -1) by default") {
        StatementPtr node = make_node<NumberLiteral>(5.0);
        REQUIRE(node->line() == -1);
        REQUIRE(node->col() == -1);
    }

    SECTION("A Statement can be stoppable") {
        StatementPtr node = make_node<NumberLiteral>(0.0);
        REQUIRE(!node->stoppable());
        node->makeStoppable();
        REQUIRE(node->stoppable());
    }

    SECTION("A Statement has the line number of the last line") {
        StatementPtr node = make_node<NumberLiteral>(0.0);
        REQUIRE(!node->stoppable());
        node->setLastLine(1337);
        REQUIRE(node->lastLine() == 1337);
    }
}