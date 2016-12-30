//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "Environment.h"

#include "Value.h"

namespace naylang {

unsigned long Environment::size() {
    return _scope.size();
}

const Value &naylang::Environment::get(const std::string &identifier) const {
    if (_scope.find(identifier) == _scope.end()) {
        throw "Binding not found";
    }
    return _scope.at(identifier);
}

void Environment::bind(const std::string &identifier, const Value &value) {
    if (_scope.find(identifier) != _scope.end()) {
        throw "Binding already created";
    }
    _scope[identifier] = value;
}

void Environment::change(const std::string &identifier, const Value &value) {
    if (_scope.find(identifier) == _scope.end()) {
        throw "Binding not found";
    }
    _scope[identifier] = value;
}

}
