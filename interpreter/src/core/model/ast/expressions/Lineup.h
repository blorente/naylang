//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_LINEUP_H
#define NAYLANG_LINEUP_H

#include <memory>
#include <vector>
#include <core/model/ast/expressions/Expression.h>

namespace naylang {

class Lineup : public Expression {

    std::vector<ExpressionPtr> _contents;

public:

    Lineup(const std::vector<ExpressionPtr> &values, int line, int col);
    Lineup(const std::vector<ExpressionPtr> &values);
    Lineup(int line, int col);
    Lineup();

    virtual void accept(Evaluator &evaluator);

    const std::vector<std::shared_ptr<Expression>> &contents() const;

};
} // end namespace naylang

#endif //NAYLANG_LINEUP_H
