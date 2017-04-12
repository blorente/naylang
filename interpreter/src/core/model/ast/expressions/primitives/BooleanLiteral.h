//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_BOOLEAN_H
#define NAYLANG_BOOLEAN_H

#include <core/model/ast/expressions/Expression.h>

namespace naylang {
class BooleanLiteral : public Expression {

    bool _value;

public:

    BooleanLiteral(bool value, int line, int col);
    BooleanLiteral(bool value);

    virtual void accept(Evaluator &evaluator);

    virtual bool operator==(const BooleanLiteral &other);
    bool value() const;
};
}


#endif //NAYLANG_BOOLEAN_H
