//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_GRACEOBJECT_H
#define NAYLANG_GRACEOBJECT_H

#include <memory>
#include <core/model/evaluators/Evaluator.h>
#include <map>
#include <vector>
#include <core/model/execution/objects/GraceObjectFactory.h>
#include <core/model/execution/methods/MethodPtr.h>
#include <core/model/execution/methods/Method.h>
#include <core/model/execution/objects/GraceObjectPtr.h>
#include <core/model/execution/methods/NativeMethod.h>

namespace naylang {

class GraceBoolean;
class GraceNumber;
class GraceString;
class GraceIterable;
class ExecutionEvaluator;
class MethodRequest;
class GraceObject;

struct ObjectCell {
    ~ObjectCell() = default;
    std::map<std::string, MethodPtr> _nativeMethods;
    std::map<std::string, MethodPtr> _userMethods;
    std::map<std::string, GraceObjectPtr> _fields;

    double _numVal;
    std::string _strVal;
    bool _boolVal;
    std::vector<GraceObjectPtr> _vectorVal;

    ObjectCell clone() {
        ObjectCell newCell;
        newCell._numVal = _numVal;
        newCell._vectorVal = _vectorVal;
        newCell._boolVal = _boolVal;
        newCell._strVal = _strVal;
        newCell._fields = _fields;
        newCell._nativeMethods = _nativeMethods;
        newCell._userMethods = _userMethods;
        return newCell;
    }
};

class GraceObject {
protected:
    ObjectCell _cell;
    GraceObjectPtr _outer;

public:
    virtual GraceObjectPtr
    dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues);
    virtual void addDefaultMethods();
    virtual void addMethod(const std::string &name, MethodPtr method);
    virtual GraceObjectPtr createCopy() = 0;

    virtual const GraceBoolean &asBoolean() const;
    virtual const GraceNumber &asNumber() const;
    virtual const GraceString &asString() const;
    virtual GraceIterable &asIterable() const;
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

    virtual std::string prettyPrint(int indentLevel);

    void indent(int indentLevel, std::string &res) const;
};
} // end namespace naylang

#endif //NAYLANG_GRACEOBJECT_H
