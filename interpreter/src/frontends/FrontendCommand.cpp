//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "FrontendCommand.h"

namespace naylang {

FrontendCommand::FrontendCommand(const std::string &code) : _code{code} {}

ExecCommand::ExecCommand(const std::string &code) : FrontendCommand(code) {}

void ExecCommand::execute(Interpreter &interpreter) {
    interpreter.execute(_code);
}

LoadCommand::LoadCommand(const std::string &code) : FrontendCommand(code) {}

void LoadCommand::execute(Interpreter &interpreter) {
    std::ifstream codeFile(_code, std::ifstream::in);
    if (codeFile.is_open()) {
        std::stringstream codeBuffer;
        codeBuffer << codeFile.rdbuf();
        interpreter.execute(codeBuffer.str());
        codeFile.close();
    } else {
        throw "Grace file could not be opened";
    }
}
}