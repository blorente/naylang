//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "Return.h"

namespace naylang {

Return::Return(int line, int col) :
    Return::Statement(line, col) {}

Return::Return() : Return::Statement() {}

void Return::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

}