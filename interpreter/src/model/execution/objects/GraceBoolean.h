//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_BOOLEANOBJECT_H
#define NAYLANG_BOOLEANOBJECT_H

#include <model/execution/objects/GraceObject.h>
#include <model/ast/NodeFactory.h>
#include <model/evaluators/ExecutionEvaluator.h>
#include "model/execution/methods/NativeMethod.h"

namespace naylang {

class GraceBoolean : public GraceObject {

    bool _value;

public:

    GraceBoolean(bool value);

    virtual GraceObjectPtr dispatch(const std::string &methodName, ExecutionEvaluator &eval);
    virtual void addDefaultMethods();

    virtual const GraceBoolean &asBoolean() const;

    bool value() const;

    bool operator==(const GraceObject &rhs) const;
    bool operator!=(const GraceObject &rhs) const;

    class PrefixNot : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
        virtual int numParams();
    };

    class AndAnd : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
        virtual int numParams();
    };

};

static const std::shared_ptr<GraceBoolean> GraceTrue = make_obj<GraceBoolean>(true);
static const std::shared_ptr<GraceBoolean> GraceFalse= make_obj<GraceBoolean>(false);

} // end namespace naylang

#endif //NAYLANG_BOOLEANOBJECT_H
