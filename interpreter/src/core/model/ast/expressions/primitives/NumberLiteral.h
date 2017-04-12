//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_NUMBER_H
#define NAYLANG_NUMBER_H

#include <core/model/ast/expressions/Expression.h>

namespace naylang {

class NumberLiteral : public Expression {

    double _value;

public:

    NumberLiteral(double value, int line, int col);
    NumberLiteral(double value);

    virtual void accept(Evaluator &evaluator);

    virtual bool operator==(const NumberLiteral &other);
    double value() const;

};

}

#endif //NAYLANG_NUMBER_H
