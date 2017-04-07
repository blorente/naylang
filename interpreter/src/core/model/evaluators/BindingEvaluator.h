//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_BINDINGEVALUATOR_H
#define NAYLANG_BINDINGEVALUATOR_H

#include <core/model/evaluators/Evaluator.h>
#include <core/model/ast/declarations/ConstantDeclaration.h>
#include <core/model/ast/declarations/VariableDeclaration.h>
#include <core/model/ast/declarations/MethodDeclaration.h>
#include <core/model/ast/expressions/requests/ImplicitRequestNode.h>
#include <core/model/ast/expressions/requests/ExplicitRequestNode.h>
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
    void evaluate(ImplicitRequestNode &expression) override;
    void evaluate(ExplicitRequestNode &expression) override;

    const std::map<std::string, Declaration *> &symbolTable() const;
};

} // end namespace naylang

#endif //NAYLANG_BINDINGEVALUATOR_H
