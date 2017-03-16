//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_METHOD_H
#define NAYLANG_METHOD_H

#include <memory>
#include <model/ast/expressions/Block.h>

namespace naylang {

class Method;

typedef std::shared_ptr<Method> MethodPtr;

class Method {
    BlockPtr _code;

public:

    Method(BlockPtr code);

    const BlockPtr &code() const;

};
} // end namespace naylang

#endif //NAYLANG_METHOD_H