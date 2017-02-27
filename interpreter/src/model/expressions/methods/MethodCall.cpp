//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "MethodCall.h"

namespace naylang {
MethodCall::MethodCall(std::shared_ptr<MethodIdentifier> methodName) : _parameters{} {
    _methodName = methodName;
}
MethodCall::MethodCall(std::shared_ptr<MethodIdentifier> methodName, std::vector<ExpressionPtr> parameters) :
        _parameters{parameters} {
    _methodName = methodName;
}

void MethodCall::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const MethodIdentifier &MethodCall::getMethodName() const {
    return *_methodName;
}

const std::vector<ExpressionPtr> &MethodCall::getParameters() const {
    return _parameters;
}

}
