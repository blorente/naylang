//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "MethodDeclaration.h"

namespace naylang {

MethodDeclaration::MethodDeclaration(const std::string &name, const std::vector<DeclarationPtr> &params,
                                     const std::vector<StatementPtr> &body) :
        _name{name}, _params{params}, _body{body}{}

void MethodDeclaration::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::string &MethodDeclaration::name() const {
    return _name;
}

const std::vector<StatementPtr> & MethodDeclaration::body() const {
    return _body;
}

const std::vector<DeclarationPtr> &MethodDeclaration::params() const {
    return _params;
}
}