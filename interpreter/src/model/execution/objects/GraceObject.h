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
#include <model/execution/objects/GraceObjectFactory.h>

namespace naylang {

class GraceBoolean;
class ExecutionEvaluator;

class GraceObject {
protected:
    std::map<std::string, MethodPtr> _nativeMethods;
    std::map<std::string, MethodPtr> _userMethods;
    std::map<std::string, GraceObjectPtr> _fields;

    GraceObjectPtr _outer;

public:
    GraceObject();

    virtual GraceObjectPtr
    dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues);
    virtual void addDefaultMethods() = 0;
    virtual void addMethod(const std::string &name, MethodPtr method);

    virtual const GraceBoolean &asBoolean() const;
    virtual bool isUndefined() const;
    virtual bool isDone() const;
    virtual bool isScope() const;
    virtual bool isClosure() const;
    virtual bool isBlock() const;

    virtual GraceObjectPtr outer();
    virtual void setOuter(GraceObjectPtr outer);

    virtual bool hasField(const std::string &name) const;
    virtual void setField(const std::string &name, GraceObjectPtr value);

    virtual bool hasMethod(const std::string &name) const;
    virtual MethodPtr getMethod(const std::string &name);
    virtual GraceObjectPtr getField(const std::string &name);
};
} // end namespace naylang

#endif //NAYLANG_GRACEOBJECT_H
