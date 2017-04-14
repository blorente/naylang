//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "REPLCommand.h"

namespace naylang {

REPLCommand::REPLCommand(const std::string &code) : _code{code} {}

ExecCommand::ExecCommand(const std::string &code) : REPLCommand(code) {}

void ExecCommand::execute(REPLInterpreter &interpreter) {
    interpreter.execute(_code);
}

LoadCommand::LoadCommand(const std::string &code) : REPLCommand(code) {}

void LoadCommand::execute(REPLInterpreter &interpreter) {
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

PrintCommand::PrintCommand(const std::string &code) : REPLCommand(code) {}

void PrintCommand::execute(REPLInterpreter &interpreter) {
    interpreter.printResult(_code);
}
}