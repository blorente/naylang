//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_METHODIDENTIFIER_H
#define NAYLANG_METHODIDENTIFIER_H

#include <model/environment/identifiers/Identifier.h>

namespace naylang {

class MethodIdentifier : public Identifier {

    std::vector<std::string> _names;
    std::vector<int> _params;

public:
    MethodIdentifier(const std::string &name, int params) : _names{name}, _params{params} {}
    MethodIdentifier(const std::vector<std::string> &names, const std::vector<int> &params) {
        if (_names.size() != _params.size()) {
            throw "Method identifier lists must be the same size";
        }

        _names = names;
        _params = params;
    }

    std::string canonName() const;

    const std::vector<std::string> &names() const;
    const std::vector<int> &params() const;
};

} // end namespace naylang


#endif //NAYLANG_METHODIDENTIFIER_H
