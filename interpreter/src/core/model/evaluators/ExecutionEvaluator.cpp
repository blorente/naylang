//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "ExecutionEvaluator.h"

#include <core/control/Debugger.h>

#include <core/model/execution/methods/MethodFactory.h>

namespace naylang {

ExecutionEvaluator::ExecutionEvaluator() {
    _storage = std::make_unique<Heap>(this);
    _currentScope = create_obj<GraceScope>();
    _partial = GraceDone;
}

void ExecutionEvaluator::evaluateAST(const GraceAST &ast) {
    _partial = create_obj<GraceDoneDef>();
    for (auto inst : ast.nodes()) {
        inst->accept(*this);
    }
}

GraceObjectPtr ExecutionEvaluator::evaluateSandbox(const GraceAST &ast) {
    auto oldPart = _partial;
    _partial = create_obj<GraceDoneDef>();
    for (auto inst : ast.nodes()) {
        inst->accept(*this);
    }
    auto res = _partial;
    _partial = oldPart;
    return res;
}

void ExecutionEvaluator::evaluate(BooleanLiteral &expression) {
    _partial = create_obj<GraceBoolean>(expression.value());
}

void ExecutionEvaluator::evaluate(NumberLiteral &expression) {
    _partial = create_obj<GraceNumber>(expression.value());
}

void ExecutionEvaluator::evaluate(StringLiteral &expression) {
    _partial = create_obj<GraceString>(expression.value());
}

void ExecutionEvaluator::evaluate(ImplicitRequestNode &expression) {
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
    MethodPtr method = make_meth(expression.params(), expression.body());
    _currentScope->addMethod(expression.name(), method);
}

void ExecutionEvaluator::evaluate(Return &expression) {
    return;
}

void ExecutionEvaluator::evaluate(ExplicitRequestNode &expression) {
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
    GraceObjectPtr oldScope = _currentScope;
    _currentScope = create_obj<UserObject>();
    for (auto node : expression.statements()) {
        node->accept(*this);
    }
    _partial = _currentScope;
    _currentScope = oldScope;
}

void ExecutionEvaluator::evaluate(ConstantDeclaration &expression) {
    expression.value()->accept(*this);
    _currentScope->setField(expression.name(), _partial);
}

void ExecutionEvaluator::evaluate(VariableDeclaration &expression) {
    if (expression.value()) {
        expression.value()->accept(*this);
        _currentScope->setField(expression.name(), _partial);
    } else {
        _currentScope->setField(expression.name(), create_obj<UserObject>());
    }
}

void ExecutionEvaluator::evaluate(Block &expression) {
    auto meth = make_meth(expression.params(), expression.body());
    _partial = create_obj<GraceBlock>(meth);
}

const GraceObjectPtr &ExecutionEvaluator::partial() const {
    return _partial;
}

GraceObjectPtr ExecutionEvaluator::currentScope() const {
    return _currentScope;
}

GraceObjectPtr ExecutionEvaluator::createNewScope() {
    GraceObjectPtr newScope = create_obj<GraceScope>();
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

void ExecutionEvaluator::evaluate(Assignment &expression) {
    expression.value()->accept(*this);
    auto val = _partial;

    auto oldScope = _currentScope;
    expression.scope()->accept(*this);
    _currentScope = _partial;

    _currentScope->setField(expression.field(), val);
    _currentScope = oldScope;
}

void ExecutionEvaluator::evaluate(IfThen &expression) {
    expression.condition()->accept(*this);
    auto cond = _partial->asBoolean().value();
    if (cond) {
        for (auto exp : expression.thenPart()) {
            exp->accept(*this);
        }
    }
}

void ExecutionEvaluator::evaluate(IfThenElse &expression) {
    expression.condition()->accept(*this);
    auto cond = _partial->asBoolean().value();
    if (cond) {
        for (auto exp : expression.thenPart()) {
            exp->accept(*this);
        }
    } else {
        for (auto exp : expression.elsePart()) {
            exp->accept(*this);
        }
    }
}

void ExecutionEvaluator::evaluate(While &expression) {
    expression.condition()->accept(*this);
    auto cond = _partial->asBoolean().value();
    while (cond) {
        for (auto exp : expression.body()) {
            exp->accept(*this);
        }
        expression.condition()->accept(*this);
        cond = _partial->asBoolean().value();
    }
}
}