//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_EXPRESSION_H
#define NAYLANG_EXPRESSION_H

#include <model/Evaluable.h>

namespace  naylang {

#define ExpressionPtr std::shared_ptr<Expression>

class Expression : public Evaluable {
public:

    virtual void accept(Evaluator &evaluator) = 0;
};
}

#endif //NAYLANG_EXPRESSION_H
