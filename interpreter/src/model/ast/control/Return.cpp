//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "Return.h"

namespace naylang {

void Return::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}
}