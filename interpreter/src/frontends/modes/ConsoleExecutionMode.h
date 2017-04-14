//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_CONSOLEEXECUTIONMODE_H
#define NAYLANG_CONSOLEEXECUTIONMODE_H

#include <regex>

namespace naylang {
class ConsoleExecutionMode {
public:

    virtual void prompt() = 0;
    virtual void runCommand(const std::string &name, const std::string &body) = 0;

};
}

#endif //NAYLANG_CONSOLEEXECUTIONMODE_H
