//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "MethodCall.h"

namespace naylang {
MethodCall::MethodCall(std::shared_ptr<MethodDeclaration> declaration) : _parameters{} {
    _declaration = declaration;
}
MethodCall::MethodCall(std::shared_ptr<MethodDeclaration> declaration, std::vector<std::shared_ptr<Assignment>> parameters) :
        _parameters{parameters} {
    _declaration = declaration;
}

void MethodCall::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::shared_ptr<MethodIdentifier> & MethodCall::getMethodName() const {
    return _declaration->getCanonName();
}

const std::vector<std::shared_ptr<Assignment>> &MethodCall::getParameters() const {
    return _parameters;
}

const std::shared_ptr<MethodDeclaration> &MethodCall::declaration() const {
    return _declaration;
}

}
