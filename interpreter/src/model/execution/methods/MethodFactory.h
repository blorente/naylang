//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#ifndef NAYLANG_METHODFACTORY_H
#define NAYLANG_METHODFACTORY_H

namespace naylang {

class Method;
static std::shared_ptr<Method> make_meth(std::shared_ptr<Block> &block) {
    return std::make_shared<Method>(block);
}

static std::shared_ptr<Method> make_meth(std::shared_ptr<Block> &&block) {
    return std::make_shared<Method>(block);
}

template <typename... Args>
static std::shared_ptr<Method> make_meth(Args&&...args) {
    return std::shared_ptr<Method>{new Method{std::forward<Args>(args)...}};
};

template <typename T, typename... Args>
static std::shared_ptr<T> make_native(Args&&...args) {
    return std::shared_ptr<T>{new T{std::forward<Args>(args)...}};
};
}

#endif //NAYLANG_METHODFACTORY_H
