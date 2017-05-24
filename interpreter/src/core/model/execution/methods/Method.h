//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_METHOD_H
#define NAYLANG_METHOD_H

#include <memory>
#include <core/model/ast/expressions/Block.h>
#include <core/model/execution/objects/GraceObjectFactory.h>
#include <core/model/execution/objects/GraceObject.h>
#include "MethodRequest.h"

namespace naylang {

class ExecutionEvaluator;
class GraceObject;

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

    std::string prettyPrint(std::string name, int indentLevel) const;
};
} // end namespace naylang

#endif //NAYLANG_METHOD_H
