//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#ifndef NAYLANG_GRACEEVALUATOR_H
#define NAYLANG_GRACEEVALUATOR_H

#include "model/Evaluator.h"
#include <model/environment/Environment.h>

#include <model/expressions/primitives/Number.h>
#include <model/expressions/primitives/Boolean.h>

#include <model/expressions/Constant.h>
#include <model/expressions/Assignment.h>
#include <model/expressions/VariableDeclaration.h>
#include <model/expressions/VariableReference.h>
#include <model/expressions/IfThenElse.h>
#include <model/expressions/ExpressionBlock.h>

#include <model/expressions/operations/Addition.h>
#include <model/expressions/operations/Subtraction.h>
#include <model/expressions/operations/Multiplication.h>
#include <model/expressions/operations/Division.h>

namespace naylang {

class GraceEvaluator : public Evaluator {

    Environment _environment;
    double _partialDouble;
    bool _partialBool;

public:

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

    double getPartialDouble() const;
    bool getPartialBool() const;
};

}

#endif //NAYLANG_GRACEEVALUATOR_H
