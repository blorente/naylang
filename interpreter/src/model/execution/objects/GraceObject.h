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
public:
    GraceObject() = default;

    virtual GraceObjectPtr
    dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues);
    virtual void addDefaultMethods() = 0;
    virtual void addMethod(const std::string &name, MethodPtr method);

    virtual const GraceBoolean &asBoolean() const;
    virtual bool isUndefined() const;
    virtual bool isDone() const;
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

static const auto GraceDone = make_obj<GraceDoneDef>();

class GraceScope : public GraceObject {
public:
    GraceScope() = default;

    virtual GraceObjectPtr
    dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues);

    virtual void addDefaultMethods();
};
} // end namespace naylang

#endif //NAYLANG_GRACEOBJECT_H
