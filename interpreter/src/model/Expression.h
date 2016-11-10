#ifndef NAYLANG_EXPRESSION_H
#define NAYLANG_EXPRESSION_H

#include "Visitor.h"

namespace naylang {

class Visitor;

class Expression {
public:
    Expression() {};
    ~Expression() = default;
    virtual void accept(Visitor &visitor) {
        visitor.process(*this);
    }
};

}

#endif //NAYLANG_EXPRESSION_H
