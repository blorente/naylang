#ifndef NAYLANG_ENVIRONMENT_H
#define NAYLANG_ENVIRONMENT_H

namespace naylang {

class Environment;

class Environment {
    Environment &_parent;

public:
    Environment(Environment &parent) : _parent(parent) {}
    ~Environment() = default;
};
}

#endif //NAYLANG_ENVIRONMENT_H
