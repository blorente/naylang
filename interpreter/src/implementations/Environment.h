#ifndef NAYLANG_ENVIRONMENT_H
#define NAYLANG_ENVIRONMENT_H

#include <map>
#include <definitions/Expression.h>

namespace naylang {

class Environment {
    std::map<std::string, ExpressionPointer> _fields;
public:

    void insert(std::string symbol, ExpressionPointer value) {
    }

    template <class Ret>
    const Ret & get(std::string symbol) {
        return *_fields[symbol];
    }

    bool isEmpty() {
        return true;
    }
};
}

#endif //NAYLANG_ENVIRONMENT_H
