//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_GRACEOBJECT_H
#define NAYLANG_GRACEOBJECT_H

#include <memory>
#include <model/evaluators/Evaluator.h>

namespace naylang {

class GraceObject;
class GraceBoolean;

typedef std::shared_ptr<GraceObject> GraceObjectPtr;

class GraceObject {
public:
    GraceObject() = default;

    virtual void dispatch(const std::string &methodName, Evaluator &eval) = 0;

    virtual const GraceBoolean &asBoolean() const;
    virtual bool isUndefined() const;
    virtual bool isDone() const;
};

class GraceDone : public GraceObject {
public:

    virtual void dispatch(const std::string &methodName, Evaluator &eval);
    bool isDone() const;
};
} // end namespace naylang

#endif //NAYLANG_GRACEOBJECT_H
