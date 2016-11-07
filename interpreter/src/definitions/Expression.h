#ifndef NAYLANG_EXPRESSION_H
#define NAYLANG_EXPRESSION_H

namespace naylang {
template<class Ret>
class Expression {
public:
    Expression() {}
    ~Expression() {}
    virtual Ret evaluate() const = 0;
};
}

#endif //NAYLANG_EXPRESSION_H
