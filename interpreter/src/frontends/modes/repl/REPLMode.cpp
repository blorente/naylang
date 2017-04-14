//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "REPLMode.h"

namespace naylang {
REPLMode::REPLMode() :
        _interpreter{std::move(std::make_unique<REPLInterpreter>())} {}

void REPLMode::runCommand(const std::string &name, const std::string &body) {
    setCommand(name, body);
    _command->execute(_interpreter.get());
}

void REPLMode::setCommand(const std::string &name, const std::string &body) {
    if (name == "exec" || name == "e") {
        _command = std::make_unique<ExecCommand>(body);
    } else if (name == "load" || name == "l") {
        _command = std::make_unique<LoadCommand>(body);
    } else if (name == "print" || name == "p") {
        _command = std::make_unique<PrintCommand>(body);
    } else {
        throw "Command not found";
    }
}

void REPLMode::prompt() {
    std::cout << ">>>> ";
}

}
