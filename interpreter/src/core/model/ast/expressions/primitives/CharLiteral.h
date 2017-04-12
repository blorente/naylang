//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_CHARLITERAL_H
#define NAYLANG_CHARLITERAL_H

#include <core/model/ast/expressions/Expression.h>

namespace naylang {

class CharLiteral : public Expression {

    char _value;

public:

    CharLiteral(char value, int line, int col);
    CharLiteral(char value);

    virtual void accept(Evaluator &evaluator);

    virtual bool operator==(const CharLiteral &other);
    char value() const;
};

} // end namespace naylang

#endif //NAYLANG_CHARLITERAL_H
