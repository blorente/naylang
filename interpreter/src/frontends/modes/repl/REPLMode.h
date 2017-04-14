//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_REPLMODE_H
#define NAYLANG_REPLMODE_H

#include <string>
#include <core/control/REPLInterpreter.h>
#include <frontends/modes/repl/REPLCommand.h>
#include <frontends/modes/ConsoleExecutionMode.h>

namespace naylang {
class REPLMode : public ConsoleExecutionMode {

    std::unique_ptr<REPLCommand> _command;
    std::unique_ptr<REPLInterpreter> _interpreter;

    void setCommand(const std::string &command);

public:

    REPLMode();
    void runCommand(const std::string &line) override;
    void prompt() override;
};
}

#endif //NAYLANG_REPLMODE_H
