#ifndef NAYLANG_EXPCONDITIONAL_H
#define NAYLANG_EXPCONDITIONAL_H

#include "definitions/Expression.h"
#include "definitions/Operations.h"
#include "ExpLiteral.h"

namespace naylang {

template <class Ret>
class ExpConditional;

template <class Ret>
class ExpConditional : public Expression<Ret> {

    const Expression<Ret> &_positive, &_negative;
    const Expression<bool> &_condition;
public:
    ExpConditional(
            const Expression<bool> &condition,
            const Expression<Ret> &positive,
            const Expression<Ret> &negative) :
            _condition(condition), _positive(positive), _negative(negative){}
    ~ExpConditional() {}

    Ret evaluate() const {
        if (_condition.evaluate())
            return _positive.evaluate();

        return _negative.evaluate();
    }
};
}

#endif //NAYLANG_EXPCONDITIONAL_H
