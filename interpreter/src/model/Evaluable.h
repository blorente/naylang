//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EVALUABLE_H
#define NAYLANG_EVALUABLE_H

#include "model/Evaluator.h"

namespace naylang {

class Evaluator;

#define EvaluablePtr std::shared_ptr<Evaluable>

class Evaluable {

public:

    Evaluable() = default;
    ~Evaluable() = default;

    virtual void accept(Evaluator &evaluator) = 0;
};

}

#endif //NAYLANG_EXPRESSION_H
