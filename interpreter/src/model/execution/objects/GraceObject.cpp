//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "GraceObject.h"

namespace naylang {

const GraceBoolean & GraceObject::asBoolean() const {
    throw "Trying to cast a generic GraceObject as GraceBoolean";
}
}