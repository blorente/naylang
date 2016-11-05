#ifndef NAYLANG_LITERAL_H
#define NAYLANG_LITERAL_H

namespace naylang {
template<class T>
class Literal;

template<class T>
class Literal {
    T _value;
public:
    Literal(T value) : _value(value) {}
    ~Literal() {}

    T value() {
        return _value;
    }

    bool operator==(Literal other) {
        return _value == other.value();
    }
};

// Various useful definitions of literals
class Number : public Literal<double> {
public:
    Number(double value) : Literal<double>(value) {}
};

}


#endif //NAYLANG_LITERAL_H
