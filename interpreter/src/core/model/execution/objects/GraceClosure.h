//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//
#ifndef NAYLANG_GRACECLOSURE_H
#define NAYLANG_GRACECLOSURE_H

#include <core/model/execution/objects/GraceObject.h>
#include <core/model/execution/methods/Method.h>

namespace naylang {

class GraceClosure : public GraceObject {
    std::string _methodName;
    MethodPtr _methodPtr;
public:

    GraceClosure() = default;
    GraceClosure(const std::string &name, MethodPtr method);

    virtual void addDefaultMethods();

    virtual bool isClosure() const;

    GraceObjectPtr createCopy() override;
};
} // end namespace naylang

#endif //NAYLANG_GRACECLOSURE_H
