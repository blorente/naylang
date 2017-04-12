//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "Block.h"

namespace naylang {

void Block::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::vector<StatementPtr> &Block::body() const {
    return _body;
}

const std::vector<DeclarationPtr> &Block::params() const {
    return _params;
}

void Block::addStatement(StatementPtr statement) {
    _body.push_back(statement);
}

void Block::addParameter(DeclarationPtr param) {
    _params.push_back(param);
}

BlockPtr Block::get_shared() {
    return shared_from_this();
}

}