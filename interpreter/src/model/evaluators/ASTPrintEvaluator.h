//
// Created by borja on 4/1/17.
//

#ifndef NAYLANG_PRINTEVALUATOR_H
#define NAYLANG_PRINTEVALUATOR_H

#include "Evaluator.h"

#include <model/ast/declarations/ConstantDeclaration.h>
#include <model/ast/declarations/MethodDeclaration.h>
#include <model/ast/declarations/VariableDeclaration.h>

#include <model/ast/expressions/Block.h>
#include <model/ast/expressions/ObjectConstructor.h>
#include <model/ast/expressions/VariableReference.h>

#include <model/ast/expressions/requests/ImplicitRequestNode.h>
#include <model/ast/expressions/requests/ExplicitRequestNode.h>

#include <model/ast/expressions/primitives/BooleanLiteral.h>
#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/expressions/primitives/StringLiteral.h>
#include <model/ast/expressions/primitives/CharLiteral.h>

#include <model/ast/control/Return.h>

namespace naylang {
class ASTPrintEvaluator : public Evaluator {

    int _indentLevel;

public:
    ASTPrintEvaluator();

    void evaluate(NumberLiteral &expression) override;
    void evaluate(BooleanLiteral &expression) override;
    void evaluate(CharLiteral &expression) override;
    void evaluate(StringLiteral &expression) override;
    void evaluate(VariableReference &expression) override;
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

private:
    void indent() const;
    void increaseIndent();
    void decreaseIndent();
};
}

#endif //NAYLANG_PRINTEVALUATOR_H
