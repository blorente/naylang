//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "MethodDeclaration.h"

namespace naylang {

MethodDeclaration::MethodDeclaration(const std::string &_name, const std::shared_ptr<Block> &_body) :
        _body(_body), _name(_name) {}

void MethodDeclaration::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::string &MethodDeclaration::name() const {
    return _name;
}

BlockPtr MethodDeclaration::body() const {
    return _body;
}
}