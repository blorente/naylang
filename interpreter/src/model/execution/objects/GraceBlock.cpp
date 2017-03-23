//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "GraceBlock.h"

namespace naylang {

GraceBlock::GraceBlock(MethodPtr apply) {
    addMethod("apply", apply);
}

void GraceBlock::addDefaultMethods() {
    // add some methods
}

bool GraceBlock::isBlock() const {
    return true;
}
}