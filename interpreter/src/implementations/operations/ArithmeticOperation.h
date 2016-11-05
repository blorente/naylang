#ifndef NAYLANG_OP_SUM_H
#define NAYLANG_OP_SUM_H

#include "definitions/Operations.h"
#include "definitions/Literal.h"

namespace naylang {

enum class ArithmeticOperator{
    ADD,
    SUB,
    MUL,
    DIV
};

class ArithmeticOperation : public BinaryOperation<Number, Number, Number> {
    ArithmeticOperator _operator;
public:
    ArithmeticOperation(ArithmeticOperator op) : _operator(op) {}
    ~ArithmeticOperation() {}

    Number operate(Number left, Number right) const {
        double result = -1;
        switch (_operator) {
            case ArithmeticOperator::ADD:
                result = left.value() + right.value();
                break;
            case ArithmeticOperator::SUB:
                result = left.value() - right.value();
                break;
            case ArithmeticOperator::MUL:
                result = left.value() * right.value();
                break;
            case ArithmeticOperator::DIV:
                if (right.value() >= 0.0 && right.value() <= 0.0)
                    throw "Division by zero";

                result = left.value() / right.value();
                break;
            default:
                throw "Arithmetic Operation not recognized";
        }
        return Number(result);
    }
};
}


#endif //NAYLANG_OP_SUM_H
