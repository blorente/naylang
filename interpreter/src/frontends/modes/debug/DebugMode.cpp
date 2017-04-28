//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <iostream>
#include "DebugMode.h"

namespace naylang {
DebugMode::DebugMode(ConsoleFrontend *frontend, const std::string &filename) :
        ConsoleExecutionMode(frontend) {
    readCodeFile(filename);
    _debugger = std::make_unique<Debugger>(this, _code);
    std::cout << "Debugging file: " << filename << std::endl;
}

void DebugMode::prompt() {
    std::cout << "ndb> ";
}

void DebugMode::runCommand(const std::string &name, const std::string &body) {
    setCommand(name, body);
    _command->execute(*_debugger);
}

void DebugMode::readCodeFile(const std::string &filename) {
    std::ifstream codeFile(filename, std::ios_base::in);
    if (codeFile.is_open()) {
        std::stringstream codeBuffer;
        codeBuffer << codeFile.rdbuf();
        _code = codeBuffer.str();
        codeFile.close();
    } else {
        throw std::string{"Grace file could not be opened"};
    }
}

void DebugMode::setCommand(const std::string &name, const std::string &body) {
    if (name == "run" || name == "r") {
        _command = std::make_unique<DebugRun>();
    } else if (name == "break" || name == "b") {
        _command = std::make_unique<DebugBreak>(parseInt(body));
    } else if (name == "env" || name == "e") {
        _command = std::make_unique<DebugPrintEnv>();
    } else if (name == "print" || name == "p") {
        _command = std::make_unique<DebugPrintExp>(body);
    } else if (name == "continue" || name == "c") {
        _command = std::make_unique<DebugContinue>();
    } else if (name == "next" || name == "n") {
        _command = std::make_unique<DebugNext>();
    } else if (name == "skip" || name == "s") {
        _command = std::make_unique<DebugSkip>();
    } else {
        _command = std::make_unique<DebugInvalid>();
    }
}

int DebugMode::parseInt(const std::string &raw) {
    return std::stoi(raw);
}
}
