//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_NEXTLINEFINDER_H
#define NAYLANG_NEXTLINEFINDER_H

#include "Evaluator.h"
#include <core/model/ast/ASTNodeDefinitions.h>

namespace naylang {

class NextLineFinder : public Evaluator {

    int _nextLine;
    bool _stepIn;
    int _curLine;

public:

    int getNextLine(Statement *curNode, bool stepIn);

    void evaluate(NumberLiteral &expression) override;
    void evaluate(BooleanLiteral &expression) override;
    void evaluate(CharLiteral &expression) override;
    void evaluate(StringLiteral &expression) override;
    void evaluate(ImplicitRequestNode &expression) override;
    void evaluate(ExplicitRequestNode &expression) override;
    void evaluate(Block &expression) override;
    void evaluate(Lineup &expression) override;
    void evaluate(ObjectConstructor &expression) override;
    void evaluate(ConstantDeclaration &expression) override;
    void evaluate(VariableDeclaration &expression) override;
    void evaluate(MethodDeclaration &expression) override;
    void evaluate(IfThen &expression) override;
    void evaluate(IfThenElse &expression) override;
    void evaluate(While &expression) override;
    void evaluate(Return &expression) override;
};
} // end namespace naylang

#endif //NAYLANG_NEXTLINEFINDER_H
