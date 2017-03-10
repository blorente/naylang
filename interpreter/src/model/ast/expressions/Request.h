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

    // We use naked pointers because we don't want to worry
    // about memory management, and there is no ownership
    // with the declaration.
    const MethodDeclaration *_declaration;

public:

    Request(const std::string &methodName);
    Request(const std::string &methodName, const std::vector<ExpressionPtr> params);

    void accept(Evaluator &evaluator) override;

    void bindTo(MethodDeclaration &_binding);

    const std::string &identifier() const;
    const std::vector<ExpressionPtr> &params() const;
    const MethodDeclaration &declaration() const;
};

} // end namespace naylang

#endif //NAYLANG_REQUEST_H
