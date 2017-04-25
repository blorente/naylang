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

void DebugPrintEnv::execute(Debugger &debugger) {
    debugger.printEnvironment();
}

DebugPrintExp::DebugPrintExp(const std::string &code) : _code{code} {}

void DebugPrintExp::execute(Debugger &debugger) {
    debugger.printResult(_code);
}

void DebugContinue::execute(Debugger &debugger) {
    debugger.resume();
}

void DebugInvalid::execute(Debugger &debugger) {
    std::cout << "Command not found, try again" << std::endl;
}

void DebugNext::execute(Debugger &debugger) {
    debugger.step();
}

void DebugSkip::execute(Debugger &debugger) {
    debugger.skip();
}
}