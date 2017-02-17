//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_GRACEOBJECTFACTORY_H
#define NAYLANG_GRACEOBJECTFACTORY_H

#include "GraceObject.h"

namespace naylang {
class GraceObjectFactory {
public:

    static GraceObject createUndefined();
    static GraceObject createNumber(double value);
    static GraceObject createMethod(ExpressionBlockPtr body);
};
}


#endif //NAYLANG_GRACEOBJECTFACTORY_H
