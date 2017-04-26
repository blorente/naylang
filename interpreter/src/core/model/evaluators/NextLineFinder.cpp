//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "NextLineFinder.h"

namespace naylang {

void NextLineFinder::evaluate(NumberLiteral &expression) {
    _nextLine = _curLine + 1;
}

void NextLineFinder::evaluate(BooleanLiteral &expression) {
    _nextLine = _curLine + 1;
}

void NextLineFinder::evaluate(CharLiteral &expression) {
    _nextLine = _curLine + 1;
}

void NextLineFinder::evaluate(StringLiteral &expression) {
    _nextLine = _curLine + 1;
}

void NextLineFinder::evaluate(ImplicitRequestNode &expression) {
    _nextLine = _curLine + 1;
}

void NextLineFinder::evaluate(ExplicitRequestNode &expression) {
    _nextLine = _curLine + 1;
}

void NextLineFinder::evaluate(Block &expression) {
    if (_stepIn) {
        _nextLine = expression.body().front()->line();
    } else {
        _nextLine = expression.body().back()->line() + 1;
    }
}

void NextLineFinder::evaluate(Lineup &expression) {
    _nextLine = _curLine + 1;
}

void NextLineFinder::evaluate(ObjectConstructor &expression) {
    if (_stepIn) {
        _nextLine = expression.statements().front()->line();
    } else {
        _nextLine = expression.statements().back()->line() + 1;
    }
}

void NextLineFinder::evaluate(ConstantDeclaration &expression) {
    if (expression.stoppable()) {
        expression.value()->accept(*this);
    }
}

void NextLineFinder::evaluate(VariableDeclaration &expression) {
    if (expression.stoppable()) {
        expression.value()->accept(*this);
    }
}

void NextLineFinder::evaluate(MethodDeclaration &expression) {
    if (_stepIn) {
        _nextLine = expression.body().front()->line();
    } else {
        _nextLine = expression.body().back()->line() + 1;
    }
}

void NextLineFinder::evaluate(IfThen &expression) {
    throw "Unimplemented NextLineFinder evaluation";
}

void NextLineFinder::evaluate(IfThenElse &expression) {
    throw "Unimplemented NextLineFinder evaluation";
}

void NextLineFinder::evaluate(While &expression) {
    throw "Unimplemented NextLineFinder evaluation";
}

void NextLineFinder::evaluate(Return &expression) {
    throw "Unimplemented NextLineFinder evaluation";
}

int NextLineFinder::getNextLine(Statement *curNode, bool stepIn) {
    _curLine = curNode->line();
    _nextLine = _curLine;
    _stepIn = stepIn;
    curNode->accept(*this);
    return _nextLine;
}
}