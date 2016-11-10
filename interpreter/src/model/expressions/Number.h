#ifndef NAYLANG_LITERAL_H
#define NAYLANG_LITERAL_H

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
    Number(double value) {
        _value.doubleValue = value;
    }
    ~Number() = default;

    void accept(Visitor &visitor) {
        visitor.process(this);
    }

    NumberValue value() const {
        return _value;
    }

    bool operator==(const Number &other) const {
        return
                (_value.doubleValue == other.value().doubleValue) &&
                (_value.intValue == other.value().intValue) &&
                (_value.byteValue == other.value().byteValue);
    }
};

}

#endif //NAYLANG_LITERAL_H
