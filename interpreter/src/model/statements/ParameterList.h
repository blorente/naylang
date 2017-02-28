//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#ifndef NAYLANG_PARAMETERLIST_H
#define NAYLANG_PARAMETERLIST_H


#include <model/statements/Statement.h>
#include <vector>
#include <memory>

namespace naylang {

class ParameterList : public Statement {

    std::vector<std::shared_ptr<VariableDeclaration>> _parameters;

public:
    ParameterList(const std::vector<std::shared_ptr<VariableDeclaration>> &parameters);

    void accept(Evaluator &evaluator) override;
    const std::vector<std::shared_ptr<VariableDeclaration>> &parameters();
};

} // end namespace naylang


#endif //NAYLANG_PARAMETERLIST_H
