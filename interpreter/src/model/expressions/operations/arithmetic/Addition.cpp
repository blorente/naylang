//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "Addition.h"

namespace naylang {

Addition::Addition(ExpressionPtr lexp, ExpressionPtr rexp) {
    _leftOperand = std::move(lexp);
    _rightOperand = std::move(rexp);
}

void Addition::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

ExpressionPtr Addition::leftOperand() const {
    return _leftOperand;
}

ExpressionPtr Addition::rightOperand() const {
    return _rightOperand;
}
}