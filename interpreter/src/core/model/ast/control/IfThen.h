//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_IFTHEN_H
#define NAYLANG_IFTHEN_H

#include <memory>
#include <core/model/ast/Statement.h>
#include <core/model/ast/expressions/Block.h>

namespace naylang {
class IfThen : public Statement {

    ExpressionPtr _condition;
    std::vector<StatementPtr> _then;

public:

    IfThen(
            ExpressionPtr condition,
            std::vector<StatementPtr> thenExp,
            int line, int col);

    IfThen(
            ExpressionPtr condition,
            std::vector<StatementPtr> thenExp);

    virtual void accept(Evaluator &evaluator);
    ExpressionPtr condition() const;
    const std::vector<StatementPtr> &thenPart() const;
};
}


#endif //NAYLANG_IFTHEN_H
