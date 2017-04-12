//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <iostream>
#include <frontends/ConsoleFrontend.h>

using namespace naylang;

int main() {
    std::string command;
    ConsoleFrontend frontend;

    while (command != "quit") {
        std::cout << ">>> ";
        getline(std::cin, command);

        frontend.runCommand(command);
    }
    return 0;
}

