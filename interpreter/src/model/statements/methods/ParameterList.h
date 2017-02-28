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
    ParameterList();
    ParameterList(const std::vector<std::shared_ptr<VariableDeclaration>> &parameters);

    void accept(Evaluator &evaluator) override;
    const std::vector<std::shared_ptr<VariableDeclaration>> &parameters();

    virtual bool operator==(const ParameterList &other) const;
    virtual bool operator!=(const ParameterList &other) const;
};

} // end namespace naylang


#endif //NAYLANG_PARAMETERLIST_H
