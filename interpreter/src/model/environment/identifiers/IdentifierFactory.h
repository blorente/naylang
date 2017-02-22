//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_IDENTIFIERFACTORY_H
#define NAYLANG_IDENTIFIERFACTORY_H


#include <memory>
#include "VariableIdentifier.h"
#include "MethodIdentifier.h"

namespace naylang {

class IdentifierFactory {

public:

    static std::unique_ptr<VariableIdentifier> createVariableIdentifier(std::string name);
    static std::unique_ptr<MethodIdentifier> createMethodIdentifier(std::string name, int params);
    static std::unique_ptr<MethodIdentifier> createMethodIdentifier(
            const std::vector<std::string> &names,
            const std::vector<int> &params);

    static std::unique_ptr<MethodIdentifier> createMethodIdentifier(const MethodIdentifier &original);
    static std::unique_ptr<MethodIdentifier> createMethodIdentifier(const std::unique_ptr<MethodIdentifier> &original);
};

} // end namespace naylang


#endif //NAYLANG_IDENTIFIERFACTORY_H
