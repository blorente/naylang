//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_DEBUGMODE_H
#define NAYLANG_DEBUGMODE_H

#include <frontends/modes/ConsoleExecutionMode.h>
#include <core/control/Interpreter.h>
#include <core/control/Debugger.h>

namespace naylang {
class DebugMode : public ConsoleExecutionMode {
    std::string _code;
    std::unique_ptr<Debugger> _debugger;

public:
    DebugMode(const std::string &filename);

    void prompt() override;
    void runCommand(const std::string &name, const std::string &body) override;

private:

    void readCodeFile(const std::string &filename);
};
}

#endif //NAYLANG_DEBUGMODE_H
