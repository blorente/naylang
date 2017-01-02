//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "GraceObjectFactory.h"

namespace naylang {
GraceObject GraceObjectFactory::createNumber(double value) {
    GraceObject ret;
    ret.addField(value);
    return ret;
}

GraceObject GraceObjectFactory::createUndefined() {
    return GraceObject();
}
}