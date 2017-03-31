//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "catch.h"

#include <iostream>
#include <antlr4-runtime.h>

TEST_CASE("Parser", "[Parser]") {
    /*ANTLRInputStream input(u8"🍴 = 🍐 + \"😎\";(((x * π))) * µ + ∰; a + (x * (y ? 0 : 1) + z);");
    TLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    tokens.fill();
    for (auto token : tokens.getTokens()) {
        std::cout << token->toString() << std::endl;
    }

    TParser parser(&tokens);
    tree::ParseTree* tree = parser.main();

    std::cout << tree->toStringTree(&parser) << std::endl << std::endl;*/
}
