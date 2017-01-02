//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#ifndef NAYLANG_ENVIRONMENT_H
#define NAYLANG_ENVIRONMENT_H

#include <memory>
#include <map>
#include "Value.h"
#include "Identifier.h"

namespace naylang {

class Environment {

    std::shared_ptr<Environment> _parent;
    std::map<Identifier, Value> _scope;

public:

    Environment() = default;
    ~Environment() = default;

    unsigned long long int size();
    void bind(const Identifier &identifier, const Value &value);
    void change(const Identifier &identifier, const Value &value);
    const Value & get(const Identifier &identifier) const;

};

}


#endif //NAYLANG_ENVIRONMENT_H
