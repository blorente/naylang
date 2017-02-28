//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "BooleanNot.h"

namespace naylang {

BooleanNot::BooleanNot(ExpressionPtr operand) : _operand{operand} {}

void BooleanNot::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

ExpressionPtr BooleanNot::operand() const {
    return _operand;
}
}
