//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_GRACEITERABLE_H
#define NAYLANG_GRACEITERABLE_H

#include <core/model/execution/methods/NativeMethod.h>
#include "GraceObject.h"

namespace naylang {

class GraceIterable : public GraceObject {
public:

    GraceIterable(const std::vector<GraceObjectPtr> &contents);

    const std::vector<GraceObjectPtr> &values() const;
    void setElem(int index, GraceObjectPtr value);

    virtual void addDefaultMethods();
    virtual GraceIterable &asIterable() const;

    class Append : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class Do : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
        virtual GraceObjectPtr respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request);
    };
};
} // end namespace naylang

#endif //NAYLANG_GRACEITERABLE_H
