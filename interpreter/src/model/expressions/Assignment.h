//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_ASSIGNMENT_H
#define NAYLANG_ASSIGNMENT_H

#include <memory>

#include <model/Expression.h>

namespace naylang {

class Assignment : public Expression {

    std::string _identifier;
    std::shared_ptr<Expression> _value;

public:

    Assignment(const std::string &identifier, std::shared_ptr<Expression> value);

    virtual void accept(Evaluator &evaluator);
    const std::string &identifier() const;
    std::shared_ptr<Expression> value() const;
};

}

#endif //NAYLANG_ASSIGNMENT_H
