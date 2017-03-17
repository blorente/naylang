//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_GRACEOBJECT_H
#define NAYLANG_GRACEOBJECT_H

#include <memory>
#include <model/evaluators/Evaluator.h>
#include <map>
#include <model/evaluators/ExecutionEvaluator.h>
#include <model/execution/methods/Method.h>
#include <model/execution/Definitions.h>

namespace naylang {

class GraceBoolean;
class ExecutionEvaluator;

class GraceObject {
protected:
    std::map<std::string, MethodPtr> _nativeMethods;
public:
    GraceObject() = default;

    virtual GraceObjectPtr dispatch(const std::string &methodName, ExecutionEvaluator &eval);
    virtual void addDefaultMethods() = 0;

    virtual const GraceBoolean &asBoolean() const;
    virtual bool isUndefined() const;
    virtual bool isDone() const;
};

class GraceDone : public GraceObject {
public:
    GraceDone() = default;

    virtual GraceObjectPtr dispatch(const std::string &methodName, ExecutionEvaluator &eval);

    virtual void addDefaultMethods();

    bool isDone() const;
};
} // end namespace naylang

#endif //NAYLANG_GRACEOBJECT_H
