//
// Copyright (c) 1/5/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "MethodDeclaration.h"

namespace naylang {
MethodDeclaration::MethodDeclaration(std::shared_ptr<MethodIdentifier> canonicalName, std::shared_ptr<ParameterList> parameters, ExpressionBlockPtr body) {
    _name = canonicalName;
    _parameters = parameters;
    _body = std::move(body);
}

void MethodDeclaration::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::shared_ptr<MethodIdentifier> & MethodDeclaration::getCanonName() const {
    return _name;
}

const std::shared_ptr<ParameterList> &MethodDeclaration::parameters() const {
    return _parameters;
}

ExpressionBlockPtr MethodDeclaration::getBody() const {
    return _body;
}

}