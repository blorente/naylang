//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_CONSOLEFRONTENDLISTENER_H
#define NAYLANG_CONSOLEFRONTENDLISTENER_H

#include <core/control/REPLInterpreter.h>
#include <frontends/FrontendCommand.h>

namespace naylang {

class ConsoleFrontend {

    std::unique_ptr<Interpreter> _interpreter;
    std::unique_ptr<FrontendCommand> _command;

public:

    ConsoleFrontend();

    void runCommand(std::string line);

private:
    void setCommand(std::string command);
};
}
#endif //NAYLANG_CONSOLEFRONTENDLISTENER_H
