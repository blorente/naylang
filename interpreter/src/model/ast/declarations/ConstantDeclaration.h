//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_CONSTANTDECLARATION_H
#define NAYLANG_CONSTANTDECLARATION_H

#include <string>
#include <memory>
#include <model/ast/declarations/Declaration.h>
#include <model/ast/expressions/Expression.h>


namespace naylang {

class ConstantDeclaration : public Declaration {

    std::string _name;
    ExpressionPtr _value;

public:

    ConstantDeclaration(const std::string &identifier, ExpressionPtr value);

    virtual void accept(Evaluator &evaluator);
    const std::string &name() const;

    const std::shared_ptr<Expression> &value() const;
};

} // end namespace naylang

#endif //NAYLANG_CONSTANTDECLARATION_H
