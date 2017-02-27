//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "IdentifierFactory.h"

namespace naylang {

std::shared_ptr<naylang::VariableIdentifier> naylang::IdentifierFactory::createVariableIdentifier(std::string name) {
    return std::move(std::make_shared<VariableIdentifier>(name));
}

std::shared_ptr<naylang::MethodIdentifier>
naylang::IdentifierFactory::createMethodIdentifier(std::string name, int params) {
    auto nameList{name};
    auto paramList{params};
    return std::move(std::make_shared<MethodIdentifier>(nameList, paramList));
}

std::shared_ptr<MethodIdentifier>
IdentifierFactory::createMethodIdentifier(const std::vector<std::string> &names, const std::vector<int> &params) {
    return std::move(std::make_shared<MethodIdentifier>(names, params));
}

std::shared_ptr<MethodIdentifier> IdentifierFactory::createMethodIdentifier(const MethodIdentifier &original) {
    std::vector<std::string> names = {original.names()};
    std::vector<int> params = {original.params()};
    return std::move(std::make_shared<MethodIdentifier>(names, params));
}

std::shared_ptr<MethodIdentifier>
IdentifierFactory::createMethodIdentifier(const std::shared_ptr<MethodIdentifier> &original) {
    return IdentifierFactory::createMethodIdentifier(*original);
}

}
