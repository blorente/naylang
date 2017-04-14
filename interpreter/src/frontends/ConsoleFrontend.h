//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_CONSOLEFRONTENDLISTENER_H
#define NAYLANG_CONSOLEFRONTENDLISTENER_H

#include <memory>
#include <frontends/modes/ConsoleExecutionMode.h>

namespace naylang {

class ConsoleFrontend {

    std::unique_ptr<ConsoleExecutionMode> _mode;
    bool _quit;

public:

    ConsoleFrontend();
    void run();

private:

    bool handleMetaCommand(const std::string &name, const std::string & body);

    std::string getCommandName(const std::string &line) const;
    std::string getCommandBody(const std::string &line) const;

};
}
#endif //NAYLANG_CONSOLEFRONTENDLISTENER_H
