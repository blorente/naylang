#ifndef NAYLANG_CONSTANT_H
#define NAYLANG_CONSTANT_H

#include <string>
#include <memory>
#include "model/Expression.h"
#include "model/Visitor.h"

#include <iostream>

namespace naylang {

typedef std::string LValue;

class Constant : public Expression {

    LValue _identifier;
    std::shared_ptr<Expression> _value;

public:
    Constant(LValue identifier, std::shared_ptr<Expression> value)
            : _identifier(identifier), _value(value) 
            {}

    ~Constant() {
    	std::cout << "~Constant()" << std::endl;
    }

    const Expression & value();
};
}

#endif //NAYLANG_CONSTANT_H
