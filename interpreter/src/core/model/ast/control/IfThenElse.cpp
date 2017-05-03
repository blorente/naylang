//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "IfThenElse.h"

namespace naylang {
IfThenElse::IfThenElse(
        ExpressionPtr condition,
        std::vector<StatementPtr> thenExp,
        std::vector<StatementPtr> elseExp) :
        IfThenElse(condition, thenExp, elseExp, -1, -1) {}

IfThenElse::IfThenElse(ExpressionPtr condition, std::vector<StatementPtr> thenExp, std::vector<StatementPtr> elseExp, int line, int col) :
        IfThenElse::Statement(line, col) {
    _condition = std::move(condition);
    _then = thenExp;
    _else = elseExp;
}

void IfThenElse::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

ExpressionPtr IfThenElse::condition() const {
    return _condition;
}

const std::vector<StatementPtr> &IfThenElse::thenPart() const {
    return _then;
}

const std::vector<StatementPtr> &IfThenElse::elsePart() const {
    return _else;
}


}