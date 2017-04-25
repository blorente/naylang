//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_CONSOLEEXECUTIONMODE_H
#define NAYLANG_CONSOLEEXECUTIONMODE_H

#include <regex>
#include <frontends/ConsoleFrontend.h>

namespace naylang {

class ConsoleFrontend;
class FrontendCommand;
class ConsoleExecutionMode {
protected:

    ConsoleFrontend *_frontend;

public:

    ConsoleExecutionMode(ConsoleFrontend *frontend) : _frontend{frontend} {}
    virtual void prompt() = 0;
    virtual void runCommand(const std::string &name, const std::string &body) = 0;
    virtual FrontendCommand getNextCommand();
    virtual void executeNextCommand();

private:

    std::string getCommandName(const std::string &line) const  {
        return line.substr(0, line.find(" "));
    }

    std::string getCommandBody(const std::string &line) const  {
        if (line.find(" ") != -1) {
            return std::regex_replace(line.substr(line.find(" ")), std::regex("^ +"), "");
        } else {
            return "";
        }
    }
};
}

#endif //NAYLANG_CONSOLEEXECUTIONMODE_H
