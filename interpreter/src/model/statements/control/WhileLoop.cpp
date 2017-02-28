//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//


#include "WhileLoop.h"

namespace naylang {

WhileLoop::WhileLoop(ExpressionPtr condition, ExpressionBlockPtr body) :
        _condition{condition}, _body{body} {}

void WhileLoop::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

ExpressionPtr WhileLoop::condition() const {
    return _condition;
}

ExpressionBlockPtr WhileLoop::body() const {
    return _body;
}
}