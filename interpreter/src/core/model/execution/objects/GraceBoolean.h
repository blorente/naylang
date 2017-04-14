//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_BOOLEANOBJECT_H
#define NAYLANG_BOOLEANOBJECT_H

#include <core/model/execution/objects/GraceObject.h>
#include <core/model/ast/NodeFactory.h>
#include <core/model/evaluators/ExecutionEvaluator.h>
#include <core/model/execution/methods/NativeMethod.h>

namespace naylang {

class GraceBoolean : public GraceObject {

    bool _value;

public:

    GraceBoolean(bool value);

    virtual GraceObjectPtr
    dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues) override;
    virtual void addDefaultMethods() override;

    virtual const GraceBoolean &asBoolean() const override;

    bool value() const;

    std::string prettyPrint(int indentLevel) override;

    bool operator==(const GraceObject &rhs) const;
    bool operator!=(const GraceObject &rhs) const;

    class PrefixNot : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class AndAnd : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class OrOr : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class Not : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class AsString : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };
};

static const std::shared_ptr<GraceBoolean> GraceTrue = make_obj<GraceBoolean>(true);
static const std::shared_ptr<GraceBoolean> GraceFalse= make_obj<GraceBoolean>(false);

} // end namespace naylang

#endif //NAYLANG_BOOLEANOBJECT_H
