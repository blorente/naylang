//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "IfThen.h"

namespace naylang {
IfThen::IfThen(ExpressionPtr condition, BlockPtr thenExp) :
        _condition{condition}, _then{thenExp} {}

void IfThen::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

ExpressionPtr IfThen::condition() const {
    return _condition;
}

BlockPtr IfThen::thenExpression() const {
    return _then;
}
}