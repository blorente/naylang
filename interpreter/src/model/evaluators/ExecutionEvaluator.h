//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EXECUTIONEVALUATOR_H
#define NAYLANG_EXECUTIONEVALUATOR_H

#include <model/evaluators/Evaluator.h>
#include <model/execution/objects/GraceObject.h>
#include <stack>

namespace naylang {

class ExecutionEvaluator : public Evaluator {

    std::stack<GraceObjectPtr> _objStack;

public:

    const std::stack<GraceObjectPtr> &objectStack() const;

    virtual void evaluate(BooleanLiteral &expression);
};
} // end namespace naylang

#endif //NAYLANG_EXECUTIONEVALUATOR_H
