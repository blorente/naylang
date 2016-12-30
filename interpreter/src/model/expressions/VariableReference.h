//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_VARIABLEREFERENCE_H
#define NAYLANG_VARIABLEREFERENCE_H

#include <model/Expression.h>
#include <string>

namespace naylang {

class VariableReference : public Expression {

    std::string _identifier;

public:

    VariableReference(const std::string &identifier);

    virtual void accept(Evaluator &evaluator);
    const std::string &identifier() const;
};

}


#endif //NAYLANG_VARIABLEREFERENCE_H
