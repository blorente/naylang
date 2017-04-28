//
// Created by borja on 4/7/17.
//

#include "ConsoleFrontend.h"
#include <frontends/modes/repl/REPLMode.h>
#include <frontends/modes/debug/DebugMode.h>

namespace naylang {

ConsoleFrontend::ConsoleFrontend() :
        _mode{std::move(std::make_unique<REPLMode>(this))},
        _quit{false} {}

void ConsoleFrontend::run() {
    std::string line;
    while (!_quit) {
        promptAndRun();
    }
}

void ConsoleFrontend::promptAndRun() {
    _mode->prompt();
    FrontendCommand command = _mode->getNextCommand();
    if (!handleMetaCommand(command.name, command.body)) {
        _mode->runCommand(command.name, command.body);
    }
}

bool ConsoleFrontend::handleMetaCommand(const std::string &name, const std::string & body) {
    bool handled = false;
    if (name == "quit") {
        _quit = true;
        handled = true;
    } else if (name == "debug" || name == "d") {
        _mode = std::make_unique<DebugMode>(this, body);
        handled = true;
    } else if (name == "interactive" || name == "repl") {
        _mode = std::make_unique<REPLMode>(this);
        handled = true;
    }
    return handled;
}
}
