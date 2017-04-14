//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//


#ifndef NAYLANG_DEBUGCOMMAND_H
#define NAYLANG_DEBUGCOMMAND_H

#include <core/control/Debugger.h>

namespace naylang {
class DebugCommand {
public:
    virtual void execute(Debugger &debugger) = 0;
};

class DebugRun : public DebugCommand {
public:
    void execute(Debugger &debugger) override;

};
}

#endif //NAYLANG_DEBUGCOMMAND_H
