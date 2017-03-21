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

    virtual GraceObjectPtr outer();
    virtual void setOuter(GraceObjectPtr outer);

    virtual bool hasField(const std::string &name) const;
    virtual bool hasMethod(const std::string &name) const;

    virtual void setField(const std::string &name, GraceObjectPtr value);
};

class GraceDoneDef : public GraceObject {
public:
    GraceDoneDef() = default;

    virtual GraceObjectPtr
    dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues);
    virtual void addDefaultMethods();

    bool operator==(const GraceObject& rhs) const;
    bool operator!=(const GraceObject& rhs) const;

    bool isDone() const;
};

class GraceScope : public GraceObject {
public:
    GraceScope() = default;

    virtual GraceObjectPtr dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues);
    virtual void addDefaultMethods();

    virtual bool isScope() const;
};
} // end namespace naylang

#endif //NAYLANG_GRACEOBJECT_H
