//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#ifndef NAYLANG_ENVIRONMENT_H
#define NAYLANG_ENVIRONMENT_H

#include <memory>
#include <map>
#include "Value.h"

namespace naylang {

class Environment {

    std::shared_ptr<Environment> _parent;
    std::map<std::string, Value> _scope;

public:

    Environment() = default;
    ~Environment() = default;

    unsigned long size();
    void bind(const std::string &identifier, const Value &value);
    void change(const std::string &identifier, const Value &value);
    const Value & get(const std::string &identifier) const;

};

}


#endif //NAYLANG_ENVIRONMENT_H
