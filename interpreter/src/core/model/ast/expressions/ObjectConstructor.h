//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#ifndef NAYLANG_OBJECTCONSTRUCTOR_H
#define NAYLANG_OBJECTCONSTRUCTOR_H

#include <core/model/ast/expressions/Expression.h>
#include <vector>

namespace naylang {

class ObjectConstructor : public Expression {

    std::vector<StatementPtr> _statements;

public:
    ObjectConstructor(const std::vector<StatementPtr> &statements);

    virtual void accept(Evaluator &evaluator);

    const std::vector<StatementPtr> &statements() const;
};
} // end namespace naylang

#endif //NAYLANG_OBJECTCONSTRUCTOR_H
