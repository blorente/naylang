//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_IDENTIFIER_H
#define NAYLANG_IDENTIFIER_H

#include <string>
#include <vector>
#include <memory>

namespace naylang {

#define BLANK_IDENTIFIER "(__)"

class Identifier {

public:

    virtual std::string canonName() const = 0;

    virtual bool operator<(const Identifier &other) const;
    virtual bool operator==(const Identifier &other) const;
    virtual bool operator!=(const Identifier &other) const;

};

struct less_Identifier {
    bool operator()(const std::shared_ptr<Identifier> &a,
                    const std::shared_ptr<Identifier> &b) const {
        return *a < *b;
    }
};

}


#endif //NAYLANG_STRINGIDENTIFIER_H
