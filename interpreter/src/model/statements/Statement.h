//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_STATEMENT_H
#define NAYLANG_STATEMENT_H

#include <model/Evaluable.h>

namespace  naylang {

#define StatementPtr std::shared_ptr<Statement>

class Statement : public Evaluable {
public:

    virtual void accept(Evaluator &evaluator) = 0;
};

}

#endif //NAYLANG_STATEMENT_H
