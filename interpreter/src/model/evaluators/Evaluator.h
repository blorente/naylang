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

class VariableReference;

class ConstantDeclaration;
class VariableDeclaration;
class MethodDeclaration;

class IfThen;
class IfThenElse;
class While;

class Request;
class Block;
class Lineup;

class Evaluator {

public:

    Evaluator() = default;
    virtual ~Evaluator() = default;

    // Methods left blank to be overridden by the subclasses.
    // For example, a Binding Evaluator might be only interested in
    // evaluating VariableReference and Request Statements

    // Expressions
    virtual void evaluate(NumberLiteral &expression) {}
    virtual void evaluate(BooleanLiteral &expression) {}
    virtual void evaluate(CharLiteral &expression) {}
    virtual void evaluate(StringLiteral &expression) {}

    virtual void evaluate(VariableReference &expression) {}
    virtual void evaluate(Request &expression) {}
    virtual void evaluate(Block &expression) {}
    virtual void evaluate(Lineup &expression) {}

    //Declarations
    virtual void evaluate(ConstantDeclaration &expression) {}
    virtual void evaluate(VariableDeclaration &expression) {}
    virtual void evaluate(MethodDeclaration &expression) {}

    // Control structures
    virtual void evaluate(IfThen &expression) {}
    virtual void evaluate(IfThenElse &expression) {}
    virtual void evaluate(While &expression) {}
};

}


#endif //NAYLANG_EVALUATOR_H
