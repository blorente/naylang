//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//


#ifndef NAYLANG_BOOLEANOBJECT_H
#define NAYLANG_BOOLEANOBJECT_H

#include <model/execution/objects/GraceObject.h>

namespace naylang {

class BooleanObject : public GraceObject {

public:

    bool _value;

    BooleanObject(bool value);
};
} // end namespace naylang

#endif //NAYLANG_BOOLEANOBJECT_H
