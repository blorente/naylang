//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_BINDINGEVALUATOR_H
#define NAYLANG_BINDINGEVALUATOR_H

#include <model/evaluators/Evaluator.h>
#include <model/ast/declarations/Declaration.h>
#include <map>
#include <memory>

namespace naylang {

class BindingEvaluator : public Evaluator {

    std::map<std::string, DeclarationPtr> _symbolTable;

public:

    BindingEvaluator() = default;


    void evaluate(ConstantDeclaration &expression) override;

    void evaluate(VariableDeclaration &expression) override;

    void evaluate(MethodDeclaration &expression) override;

    void evaluate(VariableReference &expression) override;
    void evaluate(Request &expression) override;

    const std::map<std::string, std::shared_ptr<Declaration>> &symbolTable() const;
};

} // end namespace naylang

#endif //NAYLANG_BINDINGEVALUATOR_H
