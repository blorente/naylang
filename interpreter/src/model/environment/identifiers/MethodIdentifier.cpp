//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "MethodIdentifier.h"

std::string naylang::MethodIdentifier::canonName() const {
    std::string cannonName;
    int i = 0;
    for (auto name : _names) {
        cannonName += name;
        for (int blank = 0; blank < _params[i]; blank++) {
            cannonName += BLANK_IDENTIFIER;
        }
        i++;
    }
    return cannonName;
}

const std::vector<std::string> &naylang::MethodIdentifier::names() const {
    return _names;
}

const std::vector<int> &naylang::MethodIdentifier::params() const {
    return _params;
}
