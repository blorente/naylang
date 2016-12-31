//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EVALUATOR_H
#define NAYLANG_EVALUATOR_H

#include "model/Expression.h"

namespace naylang {

class Expression;

class Number;
class Boolean;

class Constant;
class Assignment;
class PrimitiveOperation;
class VariableDeclaration;
class VariableReference;
class IfThenElse;
class ExpressionBlock;

class Addition;
class Subtraction;
class Multiplication;
class Division;

class Evaluator {

public:

    Evaluator() = default;
    virtual ~Evaluator() = default;

    virtual void evaluate(Number &expression) = 0;
    virtual void evaluate(Boolean &expression) = 0;

    virtual void evaluate(Constant &expression) = 0;
    virtual void evaluate(Assignment &expression) = 0;
    virtual void evaluate(VariableDeclaration &expression) = 0;
    virtual void evaluate(VariableReference &expression) = 0;
    virtual void evaluate(IfThenElse &expression) = 0;
    virtual void evaluate(ExpressionBlock &expression) = 0;

    virtual void evaluate(Addition &expression) = 0;
    virtual void evaluate(Subtraction &expression) = 0;
    virtual void evaluate(Multiplication &expression) = 0;
    virtual void evaluate(Division &expression) = 0;
};

}


#endif //NAYLANG_EVALUATOR_H
