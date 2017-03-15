//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "Lineup.h"

namespace naylang {

void Lineup::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

Lineup::Lineup(const std::vector<ExpressionPtr> &values) :
    _contents{values} {}

const std::vector<ExpressionPtr> &Lineup::contents() const {
    return _contents;
}
}