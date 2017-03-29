//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_METHOD_H
#define NAYLANG_METHOD_H

#include <memory>
#include <model/ast/expressions/Block.h>
#include <model/execution/objects/GraceObject.h>
#include <model/execution/objects/GraceObjectFactory.h>
#include <model/execution/methods/MethodFactory.h>
#include "MethodRequest.h"

namespace naylang {

class Method {
    std::vector<DeclarationPtr> _params;
    std::vector<StatementPtr> _code;

public:
    Method() = default;
    Method(BlockPtr code);
    Method(const std::vector<DeclarationPtr> &params, const std::vector<StatementPtr> &body);

    virtual GraceObjectPtr respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request);

    const std::vector<StatementPtr> &code() const;
    const std::vector<DeclarationPtr> &params() const;
};
} // end namespace naylang

#endif //NAYLANG_METHOD_H
