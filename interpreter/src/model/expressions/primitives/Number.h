//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_NUMBER_H
#define NAYLANG_NUMBER_H

#include <model/expressions/Expression.h>

namespace naylang {

class Number : public Expression {

    double _value;

public:

    Number(double value);
    virtual void accept(Evaluator &evaluator);

    virtual bool operator==(const Number &other);
    double value() const;

};

}

#endif //NAYLANG_NUMBER_H
