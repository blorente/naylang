//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_DEFINITIONS_H
#define NAYLANG_DEFINITIONS_H

#include <memory>

namespace naylang {
class GraceObject;
typedef std::shared_ptr<GraceObject> GraceObjectPtr;

class Method;
typedef std::shared_ptr<Method> MethodPtr;
}

#endif //NAYLANG_DEFINITIONS_H
