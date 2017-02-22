//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_IDENTIFIER_H
#define NAYLANG_IDENTIFIER_H

#include <string>
#include <vector>

namespace naylang {

#define BLANK_IDENTIFIER "(__)"

class Identifier {

public:

    virtual std::string canonName() const = 0;
    virtual bool operator<(const Identifier &other) const;
    virtual bool operator==(const Identifier &other) const;
    virtual bool operator!=(const Identifier &other) const;
};
}


#endif //NAYLANG_STRINGIDENTIFIER_H
