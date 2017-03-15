//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_NODEFACTORY_H
#define NAYLANG_NODEFACTORY_H

namespace naylang {

template <typename T, typename... Args>
static std::shared_ptr<T> make_node(Args&&...args) {
    return std::shared_ptr<T>{new T{std::forward<Args>(args)...}};
};

}

#endif //NAYLANG_NODEFACTORY_H
