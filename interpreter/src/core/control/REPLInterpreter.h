//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_REPLINTERPRETER_H
#define NAYLANG_REPLINTERPRETER_H

#include <core/parser/NaylangParserVisitor.h>
#include "Interpreter.h"

namespace naylang {
class REPLInterpreter : public Interpreter {

public:
    void execute(const std::string &line);
};
}

#endif //NAYLANG_REPLINTERPRETER_H
