//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//


#ifndef NAYLANG_STRINGLITERAL_H
#define NAYLANG_STRINGLITERAL_H

#include <core/model/ast/expressions/Expression.h>

#include <string>

namespace naylang {

class StringLiteral : public Expression {

    std::string _value;

public:

    StringLiteral(const std::string &value, int line, int col);
    StringLiteral(const std::string &value);

    void accept(Evaluator &evaluator);

    const std::string &value() const;

    bool operator==(const StringLiteral &rhs) const;
    bool operator!=(const StringLiteral &rhs) const;
};

} // end namespace naylang

#endif //NAYLANG_STRINGLITERAL_H
