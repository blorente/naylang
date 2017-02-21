//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "MethodCall.h"

namespace naylang {
MethodCall::MethodCall(Identifier methodName) : _methodName{methodName}, _parameters{} {}
MethodCall::MethodCall(Identifier methodName, std::vector<ExpressionPtr> parameters) :
        _methodName(methodName),
        _parameters{parameters} {}

void MethodCall::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const Identifier &MethodCall::getMethodName() const {
    return _methodName;
}

const std::vector<ExpressionPtr > &MethodCall::getParameters() const {
    return _parameters;
}

}
