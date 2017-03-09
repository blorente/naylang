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

namespace naylang {

class Request : public Expression {

    std::string _name;
    std::vector<ExpressionPtr> _params;

public:

    Request(const std::string &methodName, const std::vector<ExpressionPtr> params);

    void accept(Evaluator &evaluator) override;

    const std::string &method() const;
    const std::vector<ExpressionPtr> &params() const;
};

} // end namespace naylang

#endif //NAYLANG_REQUEST_H
