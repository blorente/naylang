//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <iostream>
#include "DebugMode.h"

naylang::DebugMode::DebugMode(const std::string &filename) {
    readCodeFile(filename);
    _debugger = std::make_unique<Debugger>(_code);
    std::cout << "Debugging file: " << filename << std::endl;
}

void naylang::DebugMode::prompt() {
    std::cout << "ndb> ";
}

void naylang::DebugMode::runCommand(const std::string &name, const std::string &body) {
    std::cout << "Run debug mode " + name + " " + body << std::endl;
}

void naylang::DebugMode::readCodeFile(const std::string &filename) {
    std::ifstream codeFile(filename, std::ios_base::in);
    if (codeFile.is_open()) {
        std::stringstream codeBuffer;
        codeBuffer << codeFile.rdbuf();
        _code = codeBuffer.str();
        codeFile.close();
    } else {
        throw "Grace file could not be opened";
    }
}
