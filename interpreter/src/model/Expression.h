#ifndef NAYLANG_EXPRESSION_H
#define NAYLANG_EXPRESSION_H

#include "model/Visitor.h"

namespace naylang {

class Visitor;

class Expression {
public:
    Expression() = default;
    virtual ~Expression() = default;
    // Support move
    Expression(Expression&&) = default;
    Expression& operator=(Expression&&) = default;
    // Support copy
    Expression(const Expression&) = default;
    Expression& operator=(const Expression&) = default;

};

}

#endif //NAYLANG_EXPRESSION_H
