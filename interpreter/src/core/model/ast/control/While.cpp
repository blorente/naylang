//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "While.h"

namespace naylang {

While::While(ExpressionPtr condition, const std::vector<StatementPtr> &body, int line, int col) :
        _condition{condition}, _body{body}, While::Statement(line, col) {}

    While::While(ExpressionPtr condition, const std::vector<StatementPtr> &body) :
        While(condition, body, -1, -1) {}

void While::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

ExpressionPtr While::condition() const {
    return _condition;
}

const std::vector<StatementPtr> &While::body() const {
    return _body;
}
}