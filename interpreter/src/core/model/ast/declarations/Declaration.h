//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_DECLARATION_H
#define NAYLANG_DECLARATION_H

#include <core/model/ast/Statement.h>
#include <string>

namespace naylang {

class Declaration;

typedef std::shared_ptr<Declaration> DeclarationPtr;

class Declaration : public Statement {
public:

    virtual void accept(Evaluator &evaluator) = 0;
    virtual const std::string &name() const = 0;
};

} // end namespace naylang

#endif //NAYLANG_DECLARATION_H
