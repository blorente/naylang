//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_CONSTANT_H
#define NAYLANG_CONSTANT_H

#include <model/Evaluator.h>
#include <memory>

namespace naylang {

class Constant : public Expression {

    std::string _identifier;
    std::shared_ptr<Expression> _value;

public:

    Constant(const std::string &identifier, std::shared_ptr<Expression> value);

    virtual void accept(Evaluator &evaluator);
    const std::string &identifier() const;
    std::shared_ptr<Expression> value() const;
};

}


#endif //NAYLANG_CONSTANT_H
