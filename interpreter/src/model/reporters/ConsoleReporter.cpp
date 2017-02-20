//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "ConsoleReporter.h"

void naylang::ConsoleReporter::report(const std::string &message) {
    std::cout << message << "\n";
}
