#ifndef NAYLANG_EXPRESSION_H
#define NAYLANG_EXPRESSION_H

namespace naylang {

class ExpressionBase {
public:
    ExpressionBase() {}
    ~ExpressionBase() = default;
};

#define ExpressionPointer std::unique_ptr<ExpressionBase>

class Expression {
public:
    template <typename Ret>
    virtual Ret evaluate() const = 0;
};
}

#endif //NAYLANG_EXPRESSION_H
