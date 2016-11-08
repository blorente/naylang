#ifndef NAYLANG_LITERAL_H
#define NAYLANG_LITERAL_H

#include "definitions/Expression.h"

namespace naylang {
template<class T>
class Literal;

template<class T>
class Literal : public Expression<T> {
    T _value;
public:
    Literal(T value) : _value(value) {}
    ~Literal() {}

    T evaluate() const {
        return _value;
    }

    bool operator==(const Expression<T> &other) const {
        return _value == other.evaluate();
    }
};

// Various useful definitions of literals
class Number : public Literal<double> {
public:
    Number(double value) : Literal<double>(value) {}
};

class Boolean : public Literal<bool> {
public:
    Boolean(bool value) : Literal<bool>(value) {}
};

}


#endif //NAYLANG_LITERAL_H
