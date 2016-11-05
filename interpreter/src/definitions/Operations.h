#ifndef NAYLANG_OPERATIONS_H
#define NAYLANG_OPERATIONS_H

#include "Expression.h"

namespace naylang {

template<typename In, typename Ret>
class UnaryOperation;

template<typename InA, typename InB, typename Ret>
class BinaryOperation;

template<typename In, typename Ret>
class UnaryOperation {
public:
    UnaryOperation() {}
    ~UnaryOperation() {}
    virtual Ret operate(In exp) const = 0;
};

template<typename InA, typename InB, typename Ret>
class BinaryOperation {
public:
    BinaryOperation() {}
    ~BinaryOperation() {}
    virtual Ret operate(InA val1, InB val2) const = 0;
};
}

#endif //NAYLANG_OPERATIONS_H
