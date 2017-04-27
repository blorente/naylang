//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "ExecutionEvaluator.h"

#include <core/control/Debugger.h>

#include <core/model/execution/objects/GraceBoolean.h>
#include <core/model/execution/objects/GraceNumber.h>
#include <core/model/execution/objects/GraceString.h>
#include <core/model/execution/objects/GraceScope.h>
#include <core/model/execution/objects/GraceDoneDef.h>
#include <core/model/execution/objects/UserObject.h>
#include <core/model/execution/objects/GraceBlock.h>
#include <core/model/execution/methods/MethodFactory.h>

namespace naylang {
ExecutionEvaluator::ExecutionEvaluator() :
        ExecutionEvaluator(nullptr) {}

ExecutionEvaluator::ExecutionEvaluator(Debugger *debugger) :
        _currentScope{make_obj<GraceScope>()},
        _partial{make_obj<GraceDoneDef>()},
        _debugger{debugger} {
    _debugging = _debugger != nullptr;
}

void ExecutionEvaluator::evaluateAST(const GraceAST &ast) {
    _partial = make_obj<GraceDoneDef>();
    for (auto inst : ast.nodes()) {
        inst->accept(*this);
    }
}


GraceObjectPtr ExecutionEvaluator::evaluateSandbox(const GraceAST &ast) {
    auto oldPart = _partial;
    _partial = make_obj<GraceDoneDef>();
    for (auto inst : ast.nodes()) {
        inst->accept(*this);
    }
    auto res = _partial;
    _partial = oldPart;
    return res;
}

void ExecutionEvaluator::evaluate(BooleanLiteral &expression) {
    if (debug(&expression))
        return;

    _partial = make_obj<GraceBoolean>(expression.value());
}

void ExecutionEvaluator::evaluate(NumberLiteral &expression) {
    if (debug(&expression))
        return;

    _partial = make_obj<GraceNumber>(expression.value());
}

void ExecutionEvaluator::evaluate(StringLiteral &expression) {
    if (debug(&expression))
        return;

    _partial = make_obj<GraceString>(expression.value());
}

void ExecutionEvaluator::evaluate(ImplicitRequestNode &expression) {
    if (debug(&expression))
        return;

    if (expression.params().size() == 0) {
        if (_currentScope->hasField(expression.identifier())) {
            _partial = _currentScope->getField(expression.identifier());
            return;
        }
    }

    std::vector<GraceObjectPtr> paramValues;
    for (int i = 0; i < expression.params().size(); i++) {        
        expression.params()[i]->accept(*this);
        paramValues.push_back(_partial);
    }

    _partial = _currentScope->dispatch(expression.identifier(), *this, paramValues);
}

void ExecutionEvaluator::evaluate(MethodDeclaration &expression) {
    if (debug(&expression))
        return;
    
    MethodPtr method = make_meth(expression.params(), expression.body());
    _currentScope->addMethod(expression.name(), method);
}

void ExecutionEvaluator::evaluate(Return &expression) {
    if (debug(&expression))
        return;
    return;
}

void ExecutionEvaluator::evaluate(ExplicitRequestNode &expression) {
    if (debug(&expression))
        return;
    
    expression.receiver()->accept(*this);
    auto self = _partial;

    if (expression.params().size() == 0) {
        if (self->hasField(expression.identifier())) {
            _partial = self->getField(expression.identifier());
            return;
        }
    }

    std::vector<GraceObjectPtr> paramValues;
    for (auto param : expression.params()) {
        param->accept(*this);
        paramValues.push_back(_partial);
    }
    _partial = self->dispatch(expression.identifier(), *this, paramValues);

}

void ExecutionEvaluator::evaluate(ObjectConstructor &expression) {
    if (debug(&expression))
        return;
    
    GraceObjectPtr oldScope = _currentScope;
    _currentScope = make_obj<UserObject>();
    for (auto node : expression.statements()) {
        node->accept(*this);
    }
    _partial = _currentScope;
    _currentScope = oldScope;

}

void ExecutionEvaluator::evaluate(ConstantDeclaration &expression) {
    if (debug(&expression))
        return;
    
    expression.value()->accept(*this);
    _currentScope->setField(expression.name(), _partial);

}

void ExecutionEvaluator::evaluate(VariableDeclaration &expression) {
    if (debug(&expression))
        return;
    
    if (expression.value()) {
        expression.value()->accept(*this);
        _currentScope->setField(expression.name(), _partial);
    } else {
        _currentScope->setField(expression.name(), make_obj<UserObject>());
    }
    
}

void ExecutionEvaluator::evaluate(Block &expression) {
    if (debug(&expression))
        return;
    
    auto meth = make_meth(expression.params(), expression.body());
    _partial = make_obj<GraceBlock>(meth);
}

const GraceObjectPtr &ExecutionEvaluator::partial() const {
    return _partial;
}

GraceObjectPtr ExecutionEvaluator::currentScope() const {
    return _currentScope;
}

GraceObjectPtr ExecutionEvaluator::createNewScope() {
    GraceObjectPtr newScope = make_obj<GraceScope>();
    newScope->setOuter(_currentScope);
    _currentScope = newScope;
    return newScope;
}

void ExecutionEvaluator::restoreScope() {
    _currentScope = _currentScope->outer();
}

void ExecutionEvaluator::setScope(GraceObjectPtr scope) {
    _currentScope = scope;
}

bool ExecutionEvaluator::debug(Statement *node) {
    if (_debugging) {
        return _debugger->debug(node);
    }
}

}