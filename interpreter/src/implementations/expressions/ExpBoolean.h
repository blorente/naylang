#ifndef NAYLANG_EXPBOOLEAN_H
#define NAYLANG_EXPBOOLEAN_H

#include "definitions/Expression.h"
#include "definitions/Literal.h"

namespace naylang {

class ExpBoolean;

class ExpBoolean : public Expression<Boolean> {
    Boolean _value;
public:
    ExpBoolean(Boolean value) : _value(value) {}
    // More constructors to be added
    ~ExpBoolean() {}

    Boolean evaluate() const {
        return _value;
    }
};

}


#endif //NAYLANG_EXPBOOLEAN_H
