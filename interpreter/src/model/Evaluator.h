//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EVALUATOR_H
#define NAYLANG_EVALUATOR_H

#include "Evaluable.h"

namespace naylang {

class Evaluable;

class Number;
class Boolean;

class Constant;
class Assignment;
class PrimitiveOperation;
class VariableDeclaration;
class VariableReference;
class ExpressionBlock;

class IfThenElse;
class WhileLoop;

class Addition;
class Subtraction;
class Multiplication;
class Division;

class MethodDeclaration;
class MethodCall;

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
    virtual void evaluate(ExpressionBlock &expression) = 0;

    virtual void evaluate(IfThenElse &expression) = 0;
    virtual void evaluate(WhileLoop &expression) = 0;

    virtual void evaluate(Addition &expression) = 0;
    virtual void evaluate(Subtraction &expression) = 0;
    virtual void evaluate(Multiplication &expression) = 0;
    virtual void evaluate(Division &expression) = 0;

    virtual void evaluate(MethodDeclaration &expression) = 0;
    virtual void evaluate(MethodCall &expression) = 0;
};

}


#endif //NAYLANG_EVALUATOR_H
