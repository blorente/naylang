//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_BOOLEANNOT_H
#define NAYLANG_BOOLEANNOT_H

#include <memory>
#include <model/expressions/operations/UnaryOperation.h>

namespace naylang {
class BooleanNot : public UnaryOperation {

    ExpressionPtr _operand;

public:
    BooleanNot(ExpressionPtr operand);

    virtual void accept(Evaluator &evaluator);

    ExpressionPtr operand() const;
};

} // end namespace naylang


#endif //NAYLANG_BOOLEANNOT_H
