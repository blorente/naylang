//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#ifndef NAYLANG_REQUESTNODE_H
#define NAYLANG_REQUESTNODE_H

#include <model/ast/expressions/Expression.h>
#include <vector>
#include <model/ast/declarations/MethodDeclaration.h>

namespace naylang {

class RequestNode : public Expression {
protected:
    // We use naked pointers because we don't want to worry
    // about memory management, and there is no ownership
    // with the declaration.
    const MethodDeclaration *_declaration;
    std::string _name;
    std::vector<ExpressionPtr> _params;

public:

    RequestNode(const std::string &methodName);
    RequestNode(const std::string &methodName, const std::vector<ExpressionPtr> &params);

    const std::string &identifier() const;
    const std::vector<ExpressionPtr> &params() const;
    const MethodDeclaration &declaration() const;
    void bindTo(MethodDeclaration &_binding);
};
} // end namespace naylang

#endif //NAYLANG_REQUESTNODE_H
