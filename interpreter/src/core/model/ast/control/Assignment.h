//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_ASSIGNMENT_H
#define NAYLANG_ASSIGNMENT_H

#include <core/model/ast/Statement.h>
#include <core/model/ast/expressions/Expression.h>

namespace naylang {

class Assignment : public Statement {

    std::string _field;
    ExpressionPtr _scope;
    ExpressionPtr _value;

public:
    Assignment(const std::string &field, ExpressionPtr scope, ExpressionPtr value, int line, int col);
    Assignment(const std::string &field, ExpressionPtr scope, ExpressionPtr value);
    Assignment(const std::string &field, ExpressionPtr value);

    void accept(Evaluator &evaluator) override;

    const std::string &field() const;
    const ExpressionPtr &scope() const;
    const ExpressionPtr &value() const;
};
} // end namespace naylang

#endif //NAYLANG_ASSIGNMENT_H
