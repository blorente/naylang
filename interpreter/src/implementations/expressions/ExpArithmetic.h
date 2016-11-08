#ifndef NAYLANG_EXP_ARITHMETIC_H
#define NAYLANG_EXP_ARITHMETIC_H

#include "definitions/Expression.h"
#include "definitions/Operations.h"
#include "ExpLiteral.h"

namespace naylang {
class ExpArithmetic;

class ExpArithmetic : public Expression<Number> {

    Number _left_part, _right_part;
    const BinaryOperation<Number, Number, Number> &_operation;

public:
    ExpArithmetic(Number left, const BinaryOperation<Number, Number, Number> &operation, Number right) :
           _left_part(left), _operation(operation), _right_part(right) {}
    ExpArithmetic(const Expression<Number> &left,
                  const BinaryOperation<Number, Number, Number> &operation,
                  const Expression<Number> &right) :
            _left_part(left.evaluate()), _operation(operation), _right_part(right.evaluate()) {}
    ~ExpArithmetic() {}

    Number evaluate() const {
        Number n = _operation.operate(_left_part, _right_part);
        return n;
    }
};
}

#endif //NAYLANG_EXP_ARITHMETIC_H
