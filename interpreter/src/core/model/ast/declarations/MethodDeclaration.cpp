//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "MethodDeclaration.h"

namespace naylang {

MethodDeclaration::MethodDeclaration(const std::string &name, const std::vector<DeclarationPtr> &params,
                                     const std::vector<StatementPtr> &body) :
        MethodDeclaration(name, params, body, -1, -1) {}

MethodDeclaration::MethodDeclaration(const std::string &name, const std::vector<DeclarationPtr> &params,
                                     const std::vector<StatementPtr> &body, int line, int col) :
        _name{name}, _params{params}, _body{body}, MethodDeclaration::Declaration(line, col) {}

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