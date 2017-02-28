//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Return.h"

namespace naylang {

Return::Return(ExpressionPtr expression) : _expression{expression} {}

void Return::accept(Evaluator &evaluator) {
    //evaluator.evaluate(*this);
}

ExpressionPtr Return::expression() const {
    return _expression;
}
}
