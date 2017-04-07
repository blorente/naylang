//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_GRACEBLOCK_H
#define NAYLANG_GRACEBLOCK_H

#include "GraceObject.h"

namespace naylang {

class GraceBlock : public GraceObject {
public:
    virtual bool isBlock() const;

    GraceBlock(MethodPtr apply);

    virtual void addDefaultMethods();
};
} // end namespace naylang

#endif //NAYLANG_GRACEBLOCK_H
