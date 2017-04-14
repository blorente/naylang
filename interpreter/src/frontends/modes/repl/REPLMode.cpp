//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <regex>
#include "REPLMode.h"

namespace naylang {
REPLMode::REPLMode() :
        _interpreter{std::move(std::make_unique<REPLInterpreter>())} {}

void REPLMode::runCommand(const std::string &line) {
    setCommand(line);
    _command->execute(_interpreter.get());
}

void REPLMode::setCommand(const std::string &line) {
    auto commandName = line.substr(0, line.find(" "));
    auto code = regex_replace(line.substr(line.find(" ")), std::__cxx11::regex("^ +"), "");
    if (commandName == "exec" || commandName == "e") {
        _command = std::make_unique<ExecCommand>(code);
    } else if (commandName == "load" || commandName == "l") {
        _command = std::make_unique<LoadCommand>(code);
    } else if (commandName == "print" || commandName == "p") {
        _command = std::make_unique<PrintCommand>(code);
    } else {
        throw "Command not found";
    }
}

void REPLMode::prompt() {
    std::cout << ">>> ";
}

}
