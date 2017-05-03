//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include <core/model/ast/NodeFactory.h>
#include "Assignment.h"

namespace naylang {

void Assignment::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

Assignment::Assignment(const std::string &field, ExpressionPtr scope, ExpressionPtr value, int line, int col) :
        Statement(line, col),
        _field{field},
        _scope{scope},
        _value{value} {}

Assignment::Assignment(const std::string &field, ExpressionPtr scope, ExpressionPtr value) :
        Assignment(field, scope, value, -1, -1) {}

Assignment::Assignment(const std::string &field, ExpressionPtr value) :
    Assignment(field, make_node<ImplicitRequestNode>("self"), value) {}

const std::string &Assignment::field() const {
    return _field;
}

const ExpressionPtr &Assignment::scope() const {
    return _scope;
}

const ExpressionPtr &Assignment::value() const {
    return _value;
}
}