//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_STATEMENT_H
#define NAYLANG_STATEMENT_H

#include <model/evaluators/Evaluator.h>

namespace  naylang {

class Evaluator;

#define StatementPtr std::shared_ptr<Statement>

class Statement {
public:

    virtual void accept(Evaluator &evaluator) = 0;
};

}

#endif //NAYLANG_STATEMENT_H
