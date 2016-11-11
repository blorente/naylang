#ifndef NAYLANG_CONSTANT_H
#define NAYLANG_CONSTANT_H

#include <string>
#include <memory>
#include "model/Expression.h"
#include "model/Visitor.h"

namespace naylang {

typedef std::string LValue;

class Constant : public Expression {

    LValue _identifier;
    std::unique_ptr<Expression> _value;

public:
    Constant(LValue identifier, std::unique_ptr<Expression> value) {
        _identifier = identifier;
        _value = std::move(value);
    }

    const LValue & identifier();
    const Expression & value();
};
}

#endif //NAYLANG_CONSTANT_H
