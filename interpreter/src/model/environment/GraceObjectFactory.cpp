//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "GraceObjectFactory.h"

namespace naylang {
GraceObject GraceObjectFactory::createNumber(double value) {
    return GraceObject(value);
}

GraceObject GraceObjectFactory::createUndefined() {
    return GraceObject();
}
}