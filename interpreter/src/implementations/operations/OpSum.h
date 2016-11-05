#ifndef NAYLANG_OP_SUM_H
#define NAYLANG_OP_SUM_H

#include "definitions/Operations.h"
#include "definitions/Literal.h"

namespace naylang {

class OpSum : public BinaryOperation<Number, Number, Number> {
public:
    OpSum() { /* Default empty  */ }
    ~OpSum() {}

    Number operate(Number left, Number right) const {
        return Number(left.value() + right.value());
    }
};
}


#endif //NAYLANG_OP_SUM_H
