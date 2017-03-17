//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//


#ifndef NAYLANG_METHODDECLARATION_H
#define NAYLANG_METHODDECLARATION_H

#include <model/ast/declarations/Declaration.h>
#include <model/ast/expressions/Block.h>

namespace naylang {

class MethodDeclaration : public Declaration {

    BlockPtr _body;
    std::string _name;

public:

    MethodDeclaration() = default;
    MethodDeclaration(const std::string &_name, const std::shared_ptr<Block> &_body);

    void accept(Evaluator &evaluator) override;
    const std::string &name() const override;

    BlockPtr body() const;

};

} // end namespace naylang

#endif //NAYLANG_METHODDECLARATION_H
