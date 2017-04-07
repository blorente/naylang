//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "IfThenElse.h"

namespace naylang {
IfThenElse::IfThenElse(
        ExpressionPtr condition,
        BlockPtr thenExp,
        BlockPtr elseExp) {
    _condition = std::move(condition);
    _then = std::move(thenExp);
    _else = std::move(elseExp);
}

void IfThenElse::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

ExpressionPtr IfThenElse::condition() const {
    return _condition;
}

BlockPtr IfThenElse::thenExpression() const {
    return _then;
}

BlockPtr IfThenElse::elseExpression() const {
    return _else;
}


}