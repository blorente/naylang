//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "DebugCommand.h"

namespace naylang {
void DebugRun::execute(Debugger &debugger) {
    debugger.run();
}

DebugBreak::DebugBreak(int line) : _line{line} {}

void DebugBreak::execute(Debugger &debugger) {
    debugger.setBreakpoint(_line);
}
}