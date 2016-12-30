//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EXPRESSION_H
#define NAYLANG_EXPRESSION_H

#include "model/Evaluator.h"

namespace naylang {

class Evaluator;

class Expression {

public:

    Expression() = default;
    ~Expression() = default;

    virtual void accept(Evaluator &evaluator) = 0;
};

}

#endif //NAYLANG_EXPRESSION_H
