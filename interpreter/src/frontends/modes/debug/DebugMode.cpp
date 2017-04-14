//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <iostream>
#include "DebugMode.h"

void naylang::DebugMode::prompt() {
    std::cout << "ndb> ";
}

void naylang::DebugMode::runCommand(const std::string &name, const std::string &body) {
    std::cout << "Run debug mode " + name + " " + body << std::endl;
}
