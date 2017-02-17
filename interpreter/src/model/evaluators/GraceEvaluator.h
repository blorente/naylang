//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#ifndef NAYLANG_GRACEEVALUATOR_H
#define NAYLANG_GRACEEVALUATOR_H

#include "model/Evaluator.h"
#include <model/environment/Environment.h>
#include <model/environment/Identifier.h>

#include <model/expressions/primitives/Number.h>
#include <model/expressions/primitives/Boolean.h>

#include <model/statements/Constant.h>
#include <model/statements/Assignment.h>
#include <model/statements/VariableDeclaration.h>
#include <model/expressions/VariableReference.h>
#include <model/statements/IfThenElse.h>
#include <model/expressions/ExpressionBlock.h>

#include <model/expressions/operations/Addition.h>
#include <model/expressions/operations/Subtraction.h>
#include <model/expressions/operations/Multiplication.h>
#include <model/expressions/operations/Division.h>

#include <model/expressions/methods/MethodDeclaration.h>

namespace naylang {

class GraceEvaluator : public Evaluator {

    std::shared_ptr<Environment> _environment;
    double _partialDouble;
    bool _partialBool;

public:

    GraceEvaluator();
    virtual ~GraceEvaluator() = default;

    virtual void evaluate(Number &expression);
    virtual void evaluate(Boolean &expression);

    virtual void evaluate(Constant &expression);
    virtual void evaluate(VariableReference &expression);
    virtual void evaluate(Assignment &expression);
    virtual void evaluate(VariableDeclaration &expression);
    virtual void evaluate(IfThenElse &expression);
    virtual void evaluate(ExpressionBlock &expression);

    virtual void evaluate(Addition &expression);
    virtual void evaluate(Subtraction &expression);
    virtual void evaluate(Multiplication &expression);
    virtual void evaluate(Division &expression);

    virtual void evaluate(MethodDeclaration &expression);

    double getPartialDouble() const;
    bool getPartialBool() const;
};

}

#endif //NAYLANG_GRACEEVALUATOR_H
