#ifndef NAYLANG_NUMBER_H
#define NAYLANG_NUMBER_H

#include "model/Expression.h"
#include "model/visitors/NumberVisitor.h"

#include <iostream>

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
    Number(double value);
    ~Number() {
    	std::cout << "~Number()" << std::endl;
    }

    NumberValue value() const;
    bool operator==(const Number &other) const;
};

}

#endif //NAYLANG_NUMBER_H
