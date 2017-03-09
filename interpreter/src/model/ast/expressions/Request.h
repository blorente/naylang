//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_REQUEST_H
#define NAYLANG_REQUEST_H

#include <model/ast/expressions/Expression.h>
#include <string>
#include <memory>
#include <vector>
#include <model/ast/declarations/MethodDeclaration.h>

namespace naylang {

class Request : public Expression {

    std::string _name;
    std::vector<ExpressionPtr> _params;
    MethodDeclarationPtr _binding;

public:

    Request(const std::string &methodName, const std::vector<ExpressionPtr> params);

    void accept(Evaluator &evaluator) override;

    void bindTo(MethodDeclarationPtr _binding);

    const std::string &method() const;
    const std::vector<ExpressionPtr> &params() const;
    const MethodDeclarationPtr &declaration() const;
};

} // end namespace naylang

#endif //NAYLANG_REQUEST_H
