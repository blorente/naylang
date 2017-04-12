//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "Lineup.h"

namespace naylang {

Lineup::Lineup(const std::vector<ExpressionPtr> &values, int line, int col) :
        _contents{values}, Expression(line, col) {}

Lineup::Lineup(int line, int col) :
        Lineup({}, line, col) {}

Lineup::Lineup(const std::vector<ExpressionPtr> &values) :
        Lineup(values, -1, -1) {}

Lineup::Lineup() :
        Lineup({}, -1, -1) {}

void Lineup::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::vector<ExpressionPtr> &Lineup::contents() const {
    return _contents;
}
}