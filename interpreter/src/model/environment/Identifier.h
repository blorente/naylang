//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_STRINGIDENTIFIER_H
#define NAYLANG_STRINGIDENTIFIER_H

#include <string>
#include <vector>

namespace naylang {

class Identifier {

    const std::string blankIdentifier = "(__)";
    std::vector<std::string> _identifiers;

public:
    Identifier(const std::string &other) : _identifiers{other} {}
    Identifier(const std::vector<std::string> &other) : _identifiers{other} {}

    std::string identifier() const;
    virtual bool operator<(const Identifier &other) const;
    virtual bool operator==(const Identifier &other) const;
    virtual bool operator!=(const Identifier &other) const;
};
}


#endif //NAYLANG_STRINGIDENTIFIER_H
