//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//


#ifndef NAYLANG_METHODDECLARATION_H
#define NAYLANG_METHODDECLARATION_H

#include <core/model/ast/declarations/Declaration.h>
#include <core/model/ast/expressions/Block.h>

namespace naylang {

class MethodDeclaration : public Declaration {

    std::string _name;
    std::vector<DeclarationPtr> _params;
    std::vector<StatementPtr> _body;

public:
    MethodDeclaration(
            const std::string &name,
            const std::vector<DeclarationPtr> &params,
            const std::vector<StatementPtr> &body,
            int line, int col);

    MethodDeclaration(
            const std::string &name,
            const std::vector<DeclarationPtr> &params,
            const std::vector<StatementPtr> &body);

    void accept(Evaluator &evaluator) override;

    const std::string &name() const override;
    const std::vector<DeclarationPtr> &params() const;
    const std::vector<StatementPtr> &body() const;

    void setLastLine(int line) override;
};

} // end namespace naylang

#endif //NAYLANG_METHODDECLARATION_H
