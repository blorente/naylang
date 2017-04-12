//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_STATEMENT_H
#define NAYLANG_STATEMENT_H

#include <core/model/evaluators/Evaluator.h>
#include <memory>

namespace  naylang {

class Evaluator;
class Statement;

typedef std::shared_ptr<Statement> StatementPtr;

class Statement {
protected:

    int _line;
    int _col;

public:

    Statement() : _line{-1}, _col{-1} {}
    Statement(int line, int col) : _line{line}, _col{col} {}

    virtual void accept(Evaluator &evaluator) = 0;

    int line() {return _line;}
    int col() {return _col;}
};

}

#endif //NAYLANG_STATEMENT_H
