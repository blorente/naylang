//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_USEROBJECT_H
#define NAYLANG_USEROBJECT_H

#include "GraceObject.h"

namespace naylang {

class UserObject : public GraceObject {
public:
    virtual void addDefaultMethods();
};
} // end namespace naylang

#endif //NAYLANG_USEROBJECT_H
