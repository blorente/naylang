//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#ifndef NAYLANG_GRACECLOSURE_H
#define NAYLANG_GRACECLOSURE_H

#include <model/execution/objects/GraceObject.h>
#include <model/execution/methods/Method.h>

namespace naylang {

class GraceClosure : public GraceObject {
public:

    GraceClosure() = default;
    GraceClosure(const std::string &name, MethodPtr method);

    virtual void addDefaultMethods();
    virtual bool isClosure() const;
};
} // end namespace naylang

#endif //NAYLANG_GRACECLOSURE_H
