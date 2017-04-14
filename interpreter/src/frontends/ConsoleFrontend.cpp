//
// Created by borja on 4/7/17.
//

#include "ConsoleFrontend.h"
#include <frontends/modes/repl/REPLMode.h>
#include <frontends/modes/debug/DebugMode.h>

namespace naylang {

ConsoleFrontend::ConsoleFrontend() :
        _mode{std::move(std::make_unique<REPLMode>())},
        _quit{false} {}

void ConsoleFrontend::run() {
    std::string line;
    while (!_quit) {
        _mode->prompt();
        getline(std::cin, line);
        auto commandName = getCommandName(line);
        auto commandBody = getCommandBody(line);
        if (!handleMetaCommand(commandName, commandBody)) {
            _mode->runCommand(commandName, commandBody);
        }
    }
}

bool ConsoleFrontend::handleMetaCommand(const std::string &name, const std::string & body) {
    bool handled = false;
    if (name == "quit") {
        _quit = true;
        handled = true;
    } else if (name == "debug") {
        _mode = std::make_unique<DebugMode>(body);
        handled = true;
    } else if (name == "interactive" || name == "repl") {
        _mode = std::make_unique<REPLMode>();
        handled = true;
    }
    return handled;
}

std::string ConsoleFrontend::getCommandName(const std::string &line) const {
    return line.substr(0, line.find(" "));
}

std::string ConsoleFrontend::getCommandBody(const std::string &line) const {
    if (line.find(" ") != -1) {
        return std::regex_replace(line.substr(line.find(" ")), std::regex("^ +"), "");
    } else {
        return "";
    }
}
}
