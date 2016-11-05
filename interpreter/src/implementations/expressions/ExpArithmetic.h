#ifndef NAYLANG_EXP_ARITHMETIC_H
#define NAYLANG_EXP_ARITHMETIC_H

#include "definitions/Expression.h"
#include "definitions/Operations.h"
#include "definitions/Literal.h"

namespace naylang {
class ExpArithmetic;

class ExpArithmetic : public Expression<Number> {

    Number _left_part, _right_part;
    const BinaryOperation<Number, Number, Number> &_operation;

public:
    ExpArithmetic(Number left, const BinaryOperation<Number, Number, Number> &operation, Number right) :
           _left_part(left), _operation(operation), _right_part(right) {}
    ~ExpArithmetic() {}

    Number evaluate() {
        Number n = _operation.operate(_left_part, _right_part);
        return n;
    }
};
}

#endif //NAYLANG_EXP_ARITHMETIC_H
