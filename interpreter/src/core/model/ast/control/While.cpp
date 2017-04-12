//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "While.h"

namespace naylang {

While::While(BlockPtr condition, BlockPtr body, int line, int col) :
        _condition{condition}, _body{body}, While::Statement(line, col) {}

While::While(BlockPtr condition, BlockPtr body) :
        While(condition, body, -1, -1) {}

void While::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::shared_ptr<Block> &While::condition() const {
    return _condition;
}

const std::shared_ptr<Block> &While::body() const {
    return _body;
}
}