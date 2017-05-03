//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "IfThen.h"

namespace naylang {
IfThen::IfThen(ExpressionPtr condition, std::vector<StatementPtr> thenExp, int line, int col) :
        _condition{condition}, _then{thenExp}, IfThen::Statement(line, col) {}

IfThen::IfThen(ExpressionPtr condition, std::vector<StatementPtr> thenExp) :
        IfThen(condition, thenExp, -1, -1) {}

void IfThen::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

ExpressionPtr IfThen::condition() const {
    return _condition;
}

const std::vector<StatementPtr> &IfThen::thenPart() const {
    return _then;
}
}