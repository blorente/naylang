//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "IfThenElse.h"

namespace naylang {
IfThenElse::IfThenElse(
        std::shared_ptr<Expression> condition,
        std::shared_ptr<Expression> thenExp,
        std::shared_ptr<Expression> elseExp) {
    _condition = std::move(condition);
    _then = std::move(thenExp);
    _else = std::move(elseExp);
}

void IfThenElse::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

std::shared_ptr<Expression> IfThenElse::condition() const {
    return _condition;
}

std::shared_ptr<Expression> IfThenElse::thenExpression() const {
    return _then;
}

std::shared_ptr<Expression> IfThenElse::elseExpression() const {
    return _else;
}


}