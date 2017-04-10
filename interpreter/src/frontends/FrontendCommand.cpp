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
}