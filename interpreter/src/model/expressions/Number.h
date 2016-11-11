#ifndef NAYLANG_NUMBER_H
#define NAYLANG_NUMBER_H

#include "model/Expression.h"
#include "model/visitors/NumberVisitor.h"

namespace naylang {

union NumberValue {
    char byteValue;
    int intValue;
    double doubleValue;

    bool operator==(const NumberValue &other) const;
};

class Number : public Expression {
    NumberValue _value;
public:
    explicit Number(double value);

    NumberValue value() const;
    bool operator==(const Number &other) const;
};

}

#endif //NAYLANG_NUMBER_H
