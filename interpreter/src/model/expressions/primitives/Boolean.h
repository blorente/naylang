//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_BOOLEAN_H
#define NAYLANG_BOOLEAN_H

#include <model/Expression.h>

namespace naylang {
class Boolean : public Expression {

    bool _value;

public:

    Boolean(bool value);

    virtual void accept(Evaluator &evaluator);

    virtual bool operator==(const Boolean &other);
    bool value();
};
}


#endif //NAYLANG_BOOLEAN_H
