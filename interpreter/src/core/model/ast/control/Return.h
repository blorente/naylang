//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#ifndef NAYLANG_RETURN_H
#define NAYLANG_RETURN_H

#include <core/model/ast/Statement.h>

namespace naylang {

class Return : public Statement {
public:

    virtual void accept(Evaluator &evaluator);
};
} // end namespace naylang

#endif //NAYLANG_RETURN_H
