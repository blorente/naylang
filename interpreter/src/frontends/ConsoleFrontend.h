//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_CONSOLEFRONTENDLISTENER_H
#define NAYLANG_CONSOLEFRONTENDLISTENER_H

#include <memory>
#include <frontends/modes/ConsoleExecutionMode.h>

namespace naylang {

class FrontendCommand {
public:
    std::string name;
    std::string body;
    FrontendCommand(std::string _name, std::string _body) :
            name{_name}, body{_body} {}
};

class ConsoleExecutionMode;
class ConsoleFrontend {

    std::unique_ptr<ConsoleExecutionMode> _mode;
    bool _quit;

public:

    ConsoleFrontend();
    void run();
    void promptAndRun();

private:

    bool handleMetaCommand(const std::string &name, const std::string & body);
};
}
#endif //NAYLANG_CONSOLEFRONTENDLISTENER_H
