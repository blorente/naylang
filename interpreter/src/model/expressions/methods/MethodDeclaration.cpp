//
// Copyright (c) 1/5/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "MethodDeclaration.h"

namespace naylang {
MethodDeclaration::MethodDeclaration(std::unique_ptr<MethodIdentifier> canonicalName, ExpressionBlockPtr body) {
    _name = std::move(canonicalName);
    _body = std::move(body);
}

void MethodDeclaration::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::unique_ptr<MethodIdentifier> & MethodDeclaration::getCanonName() const {
    return _name;
}

ExpressionBlockPtr MethodDeclaration::getBody() const {
    return _body;
}

}