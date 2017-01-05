//
// Copyright (c) 1/5/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "MethodDeclaration.h"

namespace naylang {
MethodDeclaration::MethodDeclaration(Identifier canonicalName, ExpressionPtr body)
    : _name{canonicalName} {
    _body = std::move(body);
}

void MethodDeclaration::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const Identifier &MethodDeclaration::getCanonName() const {
    return _name;
}

ExpressionPtr MethodDeclaration::getBody() const {
    return _body;
}
}