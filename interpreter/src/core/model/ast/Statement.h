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
    bool _stoppable;
    int _nextLine;

public:

    Statement() : _line{-1}, _col{-1}, _stoppable{false}, _nextLine{-1} {}
    Statement(int line, int col) : _line{line}, _col{col}, _stoppable{false}, _nextLine{-1} {}

    virtual void accept(Evaluator &evaluator) = 0;

    int line() const {return _line;}
    int col() const {return _col;}

    bool stoppable() {return _stoppable;}
    void makeStoppable() {_stoppable = true;}

    virtual void setLastLine(int line) {_nextLine = line;}
    int lastLine() const {return _nextLine;}
};

}

#endif //NAYLANG_STATEMENT_H
