//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "IdentifierFactory.h"

namespace naylang {

std::unique_ptr<naylang::VariableIdentifier> naylang::IdentifierFactory::createVariableIdentifier(std::string name) {
    return std::move(std::make_unique<VariableIdentifier>(name));
}

std::unique_ptr<naylang::MethodIdentifier>
naylang::IdentifierFactory::createMethodIdentifier(std::string name, int params) {
    auto nameList{name};
    auto paramList{params};
    return std::move(std::make_unique<MethodIdentifier>(nameList, paramList));
}

std::unique_ptr<MethodIdentifier>
IdentifierFactory::createMethodIdentifier(const std::vector<std::string> &names, const std::vector<int> &params) {
    return std::move(std::make_unique<MethodIdentifier>(names, params));
}

std::unique_ptr<MethodIdentifier> IdentifierFactory::createMethodIdentifier(const MethodIdentifier &original) {
    std::vector<std::string> names = {original.names()};
    std::vector<int> params = {original.params()};
    return std::move(std::make_unique<MethodIdentifier>(names, params));
}

std::unique_ptr<MethodIdentifier>
IdentifierFactory::createMethodIdentifier(const std::unique_ptr<MethodIdentifier> &original) {
    return IdentifierFactory::createMethodIdentifier(*original);
}

}
