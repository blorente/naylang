//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <iostream>
#include "ConsoleExecutionMode.h"

namespace naylang {

FrontendCommand ConsoleExecutionMode::getNextCommand() {
    std::string line;
    getline(std::cin, line);
    auto commandName = getCommandName(line);
    auto commandBody = getCommandBody(line);
    return FrontendCommand{commandName, commandBody};
}

void ConsoleExecutionMode::executeNextCommand() {
    _frontend->promptAndRun();
}
}


