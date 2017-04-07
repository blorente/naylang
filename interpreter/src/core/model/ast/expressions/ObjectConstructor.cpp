//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "ObjectConstructor.h"

namespace naylang {

ObjectConstructor::ObjectConstructor(const std::vector<StatementPtr> &statements) : _statements{statements} {}

void ObjectConstructor::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::vector<StatementPtr> &ObjectConstructor::statements() const {
    return _statements;
}
}