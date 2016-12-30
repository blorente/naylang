//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#include "Addition.h"

namespace naylang {

Addition::Addition(std::shared_ptr<Expression> lexp, std::shared_ptr<Expression> rexp) {
    _leftOperand = std::move(lexp);
    _rightOperand = std::move(rexp);
}

void Addition::accept(Evaluator &evaluator) {
    evaluator.evaluate(*this);
}

std::shared_ptr<Expression> Addition::leftOperand() const {
    return _leftOperand;
}

std::shared_ptr<Expression> Addition::rightOperand() const {
    return _rightOperand;
}
}