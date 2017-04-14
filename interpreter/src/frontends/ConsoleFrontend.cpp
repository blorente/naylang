//
// Created by borja on 4/7/17.
//

#include "ConsoleFrontend.h"
#include <regex>
#include <frontends/modes/repl/REPLMode.h>

namespace naylang {

ConsoleFrontend::ConsoleFrontend() :
        _mode{std::move(std::make_unique<REPLMode>())},
        _quit{false} {}

void ConsoleFrontend::run() {
    std::string command;
    while (!_quit) {
        _mode->prompt();
        getline(std::cin, command);
        if (!handleMetaCommand(command)) {
            _mode->runCommand(command);
        }
    }
}

bool ConsoleFrontend::handleMetaCommand(const std::string &command) {
    if (command == "quit") {
        _quit = true;
        return true;
    }
    return false;
}

}
