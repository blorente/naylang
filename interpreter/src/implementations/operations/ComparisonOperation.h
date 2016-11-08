#ifndef NAYLANG_COMPARISONOPERATION_H
#define NAYLANG_COMPARISONOPERATION_H

#include "definitions/Operations.h"
#include "implementations/expressions/ExpLiteral.h"

namespace naylang {

enum class ComparisonOperator {
    EQUAL,
    NOT_EQUAL,
    GREATER,
    GREATER_OR_EQUAL,
    SMALLER,
    SMALLER_OR_EQUAL
};

class ComparisonOperation : public BinaryOperation<Number, Number, Boolean> {
    ComparisonOperator _operator;
public:
    ComparisonOperation(ComparisonOperator op) : _operator(op) {}

    ~ComparisonOperation() {}

    Boolean operate(Number left, Number right) const {
        Boolean result(false);
        switch (_operator) {
            case ComparisonOperator::EQUAL:
                result = Boolean(left.evaluate() == right.evaluate());
                break;
            case ComparisonOperator::NOT_EQUAL:
                result = Boolean(left.evaluate() != right.evaluate());
                break;
            case ComparisonOperator::GREATER:
                result = Boolean(left.evaluate() > right.evaluate());
                break;
            case ComparisonOperator::GREATER_OR_EQUAL:
                result = Boolean(left.evaluate() >= right.evaluate());
                break;
            case ComparisonOperator::SMALLER:
                result = Boolean(left.evaluate() < right.evaluate());
                break;
            case ComparisonOperator::SMALLER_OR_EQUAL:
                result = Boolean(left.evaluate() <= right.evaluate());
                break;
            default:
                throw "Arithmetic Operation not recognized";
        }
        return result;
    }
};
}

#endif //NAYLANG_COMPARATIONOPERATION_H
