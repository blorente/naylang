//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "Environment.h"

namespace naylang {

Environment::Environment(std::shared_ptr<Environment> parent) {
    _parent = std::move(parent);
}

unsigned long long int Environment::size() {
    return _scope.size();
}

const GraceObject &naylang::Environment::get(const std::shared_ptr<Identifier> &identifier) const {
    if (!bindingExistsAnywhere(identifier))
        throw "Binding not found";

    if (!bindingExistsHere(identifier))
        return _parent->get(identifier);

    return _scope.at(identifier);
}

void Environment::bind(std::shared_ptr<Identifier> identifier, const GraceObject &value) {
    if (bindingExistsAnywhere(identifier))
        throw "Binding already created";

    _scope[std::move(identifier)] = value;
}

void Environment::change(const std::shared_ptr<Identifier> &identifier, const GraceObject &value) {
    if (!bindingExistsAnywhere(identifier))
       throw "Binding not found";

    if (!bindingExistsHere(identifier))
        _parent->change(identifier, value);

    _scope[identifier] = value;
}

bool Environment::bindingExistsHere(const std::shared_ptr<Identifier> &identifier) const {
    return _scope.find(identifier) != _scope.end();
}

bool Environment::bindingExistsAnywhere(const std::shared_ptr<Identifier> &identifier) const {
    if (bindingExistsHere(identifier))
        return true;

    if (_parent)
        return _parent->bindingExistsAnywhere(identifier);
}

}
