//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_GRACEOBJECTFACTORY_H
#define NAYLANG_GRACEOBJECTFACTORY_H

namespace naylang {

template <typename T, typename... Args>
static std::shared_ptr<T> make_obj(Args&&...args) {
    return std::shared_ptr<T>{new T{std::forward<Args>(args)...}};
};
}
#endif //NAYLANG_GRACEOBJECTFACTORY_H
