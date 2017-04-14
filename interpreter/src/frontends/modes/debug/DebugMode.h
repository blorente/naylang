//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_DEBUGMODE_H
#define NAYLANG_DEBUGMODE_H

#include <frontends/modes/ConsoleExecutionMode.h>
#include <core/control/Interpreter.h>

namespace naylang {
class DebugMode : public ConsoleExecutionMode {

    std::unique_ptr<Interpreter> _interpreter;

public:
    void prompt() override;
    void runCommand(const std::string &name, const std::string &body) override;

};
}

#endif //NAYLANG_DEBUGMODE_H
