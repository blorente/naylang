//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_STATEMENT_H
#define NAYLANG_STATEMENT_H

#include <model/evaluators/Evaluator.h>
#include <memory>

namespace  naylang {

class Evaluator;
class Statement;

typedef std::shared_ptr<Statement> StatementPtr;

class Statement {
public:

    virtual void accept(Evaluator &evaluator) = 0;
};

}

#endif //NAYLANG_STATEMENT_H
