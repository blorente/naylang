//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "ParameterList.h"

namespace naylang {


ParameterList::ParameterList() {}

ParameterList::ParameterList(const std::vector<std::shared_ptr<VariableDeclaration>> &parameters) :
        _parameters{parameters} {}

void ParameterList::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

const std::vector<std::shared_ptr<VariableDeclaration>> &ParameterList::parameters() {
    return _parameters;
}

bool ParameterList::operator==(const ParameterList &other) const {
    if (_parameters.size() != other._parameters.size())
        return false;

    return std::equal(_parameters.begin(), _parameters.end(), other._parameters.begin());
}

bool ParameterList::operator!=(const ParameterList &other) const {
    return !((*this) == other);
}

}
