#ifndef NAYLANG_ENVIRONMENT_H
#define NAYLANG_ENVIRONMENT_H

#include <map>
#include <memory>
#include "model/Expression.h"

namespace naylang {

class Expression;

class Environment {
    std::shared_ptr<Environment> _parent;
    std::map<std::string, std::unique_ptr<Expression>> _values;

public:
    Environment() {}
    Environment(std::shared_ptr<Environment> parent) : _parent(parent) {}
    ~Environment() = default;

    bool isEmpty() {
        return _values.empty();
    }

    void insert(std::string name, std::unique_ptr<Expression> value) {
        _values[name] = std::move(value);
    }

    const Expression & get(std::string name) {
        return *_values[name];
    }
};

}

#endif //NAYLANG_ENVIRONMENT_H
