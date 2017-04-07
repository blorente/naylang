//
// Created by borja on 4/7/17.
//

#include <antlr4-runtime.h>
#include <ConsoleFrontendCommandsLexer.h>
#include "ConsoleFrontend.h"

using namespace antlr4;
using namespace antlr4::tree;

namespace naylang {
void ConsoleFrontend::runCommand(std::string command) {
    ANTLRInputStream stream(command);
    ConsoleFrontendCommandsLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);
    ConsoleFrontendCommandsParser parser(&tokens);

    ParseTreeWalker::DEFAULT.walk(this, parser.command());
}

void ConsoleFrontend::exitExecCommand(ConsoleFrontendCommandsParser::ExecCommandContext *ctx) {
    auto line = ctx->code()->getText();
    interpreter.execute(line);
}
}
