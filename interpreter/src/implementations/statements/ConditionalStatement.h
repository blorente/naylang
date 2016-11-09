#ifndef NAYLANG_EXPCONDITIONAL_H
#define NAYLANG_EXPCONDITIONAL_H

#include "definitions/Expression.h"
#include "definitions/Operations.h"
#include "implementations/expressions/ExpLiteral.h"

namespace naylang {

template <class Ret>
class ConditionalStatement;

template <class Ret>
class ConditionalStatement : public Statement {

    const Statement &_positive, &_negative;
    const Expression<bool> &_condition;

public:
    ConditionalStatement(
            const Expression<bool> &condition,
            const Statement &positive,
            const Statement &negative) :
            _condition(condition), _positive(positive), _negative(negative){}
    ~ConditionalStatement() {}

    void evaluate() const {
        if (_condition.evaluate()) {
            _positive.evaluate();
        } else {
            _negative.evaluate();
        }
    }
};
}

#endif //NAYLANG_EXPCONDITIONAL_H
