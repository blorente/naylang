//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_CONSOLEREPORTER_H
#define NAYLANG_CONSOLEREPORTER_H

#include <iostream>
#include <model/Evaluator.h>
#include <model/reporters/Reporter.h>

namespace naylang {

class ConsoleReporter : public Reporter {

public:
    ConsoleReporter() {}

    void report(const std::string &message);
};

} // end namespace naylang


#endif //NAYLANG_CONSOLEREPORTER_H
