//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "Environment.h"

namespace naylang {

unsigned long long int Environment::size() {
    return _scope.size();
}

const GraceObject &naylang::Environment::get(const Identifier &identifier) const {
    if (_scope.find(identifier) == _scope.end()) {
        throw "Binding not found";
    }
    return _scope.at(identifier);
}

void Environment::bind(const Identifier &identifier, const GraceObject &value) {
    if (_scope.find(identifier) != _scope.end()) {
        throw "Binding already created";
    }
    _scope[identifier] = value;
}

void Environment::change(const Identifier &identifier, const GraceObject &value) {
    if (_scope.find(identifier) == _scope.end()) {
        throw "Binding not found";
    }
    _scope[identifier] = value;
}

}
