//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#ifndef NAYLANG_ENVIRONMENT_H
#define NAYLANG_ENVIRONMENT_H

#include <memory>
#include <map>
#include "GraceObject.h"
#include "model/environment/identifiers/Identifier.h"

namespace naylang {

class GraceObject;

class Environment {

    std::shared_ptr<Environment> _parent = nullptr;
    std::map<std::unique_ptr<Identifier>, GraceObject> _scope;

public:

    Environment() = default;
    Environment(std::shared_ptr<Environment> parent);
    ~Environment() = default;

    unsigned long long int size();
    void bind(std::unique_ptr<Identifier> identifier, const GraceObject &value);
    void change(const std::unique_ptr<Identifier> &identifier, const GraceObject &value);
    const GraceObject & get(const std::unique_ptr<Identifier> &identifier) const;

private:

    bool bindingExistsHere(const std::unique_ptr<Identifier> &identifier) const;
    bool bindingExistsAnywhere(const std::unique_ptr<Identifier> &identifier) const;
};

}


#endif //NAYLANG_ENVIRONMENT_H
