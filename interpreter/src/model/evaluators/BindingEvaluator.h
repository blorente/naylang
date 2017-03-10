//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_BINDINGEVALUATOR_H
#define NAYLANG_BINDINGEVALUATOR_H

#include <model/evaluators/Evaluator.h>
#include <model/ast/declarations/ConstantDeclaration.h>
#include <model/ast/declarations/VariableDeclaration.h>
#include <model/ast/declarations/MethodDeclaration.h>
#include <model/ast/expressions/Request.h>
#include <model/ast/expressions/VariableReference.h>
#include <map>
#include <memory>

namespace naylang {

class BindingEvaluator : public Evaluator {

    // We use naked pointers because we don't have anything to do
    // with the memory management of Declaration,
    // yet we want polymorphism
    std::map<std::string, Declaration *> _symbolTable;

public:

    BindingEvaluator() = default;


    void evaluate(ConstantDeclaration &expression) override;
    void evaluate(VariableDeclaration &expression) override;
    void evaluate(MethodDeclaration &expression) override;
    void evaluate(VariableReference &expression) override;
    void evaluate(Request &expression) override;

    const std::map<std::string, Declaration *> &symbolTable() const;
};

} // end namespace naylang

#endif //NAYLANG_BINDINGEVALUATOR_H
