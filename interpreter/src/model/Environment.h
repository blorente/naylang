#ifndef NAYLANG_ENVIRONMENT_H
#define NAYLANG_ENVIRONMENT_H

#include <map>
#include "model/Pointers.h"

namespace naylang {

class Environment {
    std::shared_ptr<Environment> _parent;
    std::map<std::string, Expression *> _values;

public:
    Environment() {}
    Environment(std::shared_ptr<Environment> parent) : _parent(parent) {}
    ~Environment() = default;
};

}

#endif //NAYLANG_ENVIRONMENT_H
