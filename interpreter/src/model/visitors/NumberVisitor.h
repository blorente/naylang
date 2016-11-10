#ifndef NAYLANG_LITERALVISITOR_H
#define NAYLANG_LITERALVISITOR_H

#include "model/Visitor.h"
#include "model/expressions/Number.h"

namespace naylang {

class Number;

class NumberVisitor : Visitor {
public:
    void process(Number *exp) {

    }
};
}

#endif //NAYLANG_LITERALVISITOR_H
