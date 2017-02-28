//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_VARIABLEIDENTIFIER_H
#define NAYLANG_VARIABLEIDENTIFIER_H

#include <model/environment/identifiers/Identifier.h>

namespace naylang {

class VariableIdentifier : public Identifier {

    std::string _name;

public:

    VariableIdentifier(const std::string &other) : _name{other} {}

    std::string canonName() const;
};

} // end namespace naylang


#endif //NAYLANG_VARIABLEIDENTIFIER_H
