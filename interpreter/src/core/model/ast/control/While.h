//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_WHILE_H
#define NAYLANG_WHILE_H

#include <core/model/ast/Statement.h>
#include <core/model/ast/expressions/Block.h>
#include <bits/shared_ptr.h>
#include <memory>

namespace naylang {

class While : public Statement {

    ExpressionPtr _condition;
    std::vector<StatementPtr> _body;

public:
    While(ExpressionPtr condition, const std::vector<StatementPtr> &body, int line, int col);
    While(ExpressionPtr condition, const std::vector<StatementPtr> &body);

    void accept(Evaluator &evaluator) override;

    ExpressionPtr condition() const;
    const std::vector<StatementPtr> &body() const;
};

} // end namespace naylang

#endif //NAYLANG_WHILE_H
