//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#ifndef NAYLANG_VALUE_H
#define NAYLANG_VALUE_H

#define INVALID_VALUE Value(-99999)

namespace naylang {

class Value {

    double _value;

public:

    Value() = default;
    Value(double value) : _value(value) {}
    Value(const Value &other) = default;
    ~Value() = default;

    virtual bool operator== (const Value &other) const { return _value == other._value; }
    double value() const { return _value; }
};

}


#endif //NAYLANG_VALUE_H
