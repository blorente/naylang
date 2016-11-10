#ifndef NAYLANG_NUMBER_H
#define NAYLANG_NUMBER_H

#include "model/Expression.h"
#include "model/visitors/NumberVisitor.h"

namespace naylang {

union NumberValue {
    char byteValue;
    int intValue;
    double doubleValue;
};

class Number : public Expression {
    NumberValue _value;
public:
    Number(double value);
    ~Number() = default;

    void accept(Visitor &visitor);
    NumberValue value() const;
    bool operator==(const Number &other) const;
};

}

#endif //NAYLANG_NUMBER_H
