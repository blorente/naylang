//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_CONSOLEFRONTENDLISTENER_H
#define NAYLANG_CONSOLEFRONTENDLISTENER_H

#include <core/control/Interpreter.h>

namespace naylang {
class ConsoleFrontend {

    Interpreter interpreter;

public:
    void runCommand(std::string command);

};
}
#endif //NAYLANG_CONSOLEFRONTENDLISTENER_H
