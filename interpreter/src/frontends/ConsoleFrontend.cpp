//
// Created by borja on 4/7/17.
//

#include "ConsoleFrontend.h"

namespace naylang {
void ConsoleFrontend::runCommand(std::string line) {
    setCommand(line);
    _command->execute(_interpreter);
}

void ConsoleFrontend::setCommand(std::string line) {
    auto commandName = line.substr(0, line.find(" "));
    auto code = line.substr(line.find(" "));
    if (commandName == "exec" || commandName == "e") {
        _command = std::make_unique<ExecCommand>(code);
    } else {
        throw "Command not found";
    }
}
}
