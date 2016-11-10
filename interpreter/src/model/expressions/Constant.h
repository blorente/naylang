#ifndef NAYLANG_CONSTANT_H
#define NAYLANG_CONSTANT_H

#include <string>
#include "model/Expression.h"
#include "model/Visitor.h"

namespace naylang {

typedef std::string LValue;

class Constant : public Expression {

    LValue _identifier;
    const Expression &_value;

public:
    Constant(LValue identifier, const Expression &value)
            : _identifier(identifier), _value(value) {}

    const Expression & value();
};
}

#endif //NAYLANG_CONSTANT_H
