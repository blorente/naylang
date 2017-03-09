//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EVALUATOR_H
#define NAYLANG_EVALUATOR_H

#include <model/ast/Statement.h>

namespace naylang {

class Statement;

class NumberLiteral;
class BooleanLiteral;
class CharLiteral;
class StringLiteral;

class ConstantDeclaration;
class Assignment;
class VariableDeclaration;
class VariableReference;
class Block;

class IfThenElse;
class WhileLoop;

class MethodDeclaration;
class MethodCall;
class ParameterList;

class Evaluator {

public:

    Evaluator() = default;
    virtual ~Evaluator() = default;

    virtual void evaluate(NumberLiteral &expression) = 0;
    virtual void evaluate(BooleanLiteral &expression) = 0;
    virtual void evaluate(CharLiteral &expression) = 0;
    virtual void evaluate(StringLiteral &expression) = 0;

    virtual void evaluate(ConstantDeclaration &expression) = 0;
    virtual void evaluate(Assignment &expression) = 0;
    virtual void evaluate(VariableDeclaration &expression) = 0;
    virtual void evaluate(VariableReference &expression) = 0;
    virtual void evaluate(Block &expression) = 0;

    virtual void evaluate(IfThenElse &expression) = 0;
    virtual void evaluate(WhileLoop &expression) = 0;

    virtual void evaluate(MethodDeclaration &expression) = 0;
    virtual void evaluate(MethodCall &expression) = 0;
    virtual void evaluate(ParameterList &expression) = 0;
};

}


#endif //NAYLANG_EVALUATOR_H
