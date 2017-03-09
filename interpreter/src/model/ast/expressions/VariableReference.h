//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_VARIABLEREFERENCE_H
#define NAYLANG_VARIABLEREFERENCE_H

#include <string>
#include <memory>
#include <model/evaluators/Evaluator.h>
#include <model/ast/expressions/Expression.h>

namespace naylang {

class VariableReference : public Expression {

    std::string _name;

public:

    VariableReference(const std::string &name);

    void accept(Evaluator &evaluator) override;
    const std::string &identifier() const;
};

}


#endif //NAYLANG_VARIABLEREFERENCE_H
