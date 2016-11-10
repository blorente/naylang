#ifndef NAYLANG_EXPRESSION_H
#define NAYLANG_EXPRESSION_H

namespace naylang {

class Visitor;

class Expression {
public:
    Expression() {};
    ~Expression() = default;
    virtual void accept(Visitor &visitor) = 0;
};

}

#endif //NAYLANG_EXPRESSION_H
