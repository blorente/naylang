#ifndef NAYLANG_LITERALVISITOR_H
#define NAYLANG_LITERALVISITOR_H

#include "model/Visitor.h"
#include "model/expressions/Number.h"

namespace naylang {

class Number;

class NumberVisitor : public Visitor {
public:
    void process(Expression &exp, Environment &env);
};
}

#endif //NAYLANG_LITERALVISITOR_H
