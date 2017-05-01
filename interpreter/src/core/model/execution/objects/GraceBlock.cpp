//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "GraceBlock.h"

namespace naylang {

GraceBlock::GraceBlock(MethodPtr apply) {
    addDefaultMethods();
    addMethod("apply", apply);
}

void GraceBlock::addDefaultMethods() {
    GraceObject::addDefaultMethods();
}

bool GraceBlock::isBlock() const {
    return true;
}

GraceObjectPtr GraceBlock::createCopy() {
    return make_obj<GraceBlock>(getMethod("apply"));
}
}