//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_BOOLEANOBJECT_H
#define NAYLANG_BOOLEANOBJECT_H

#include <model/execution/objects/GraceObject.h>
#include <map>
#include <model/ast/NodeFactory.h>
#include <model/execution/methods/NativeMethod.h>
#include "model/execution/methods/Method.h"

namespace naylang {

class GraceBoolean : public GraceObject {

    bool _value;
    std::map<std::string, MethodPtr> _methodTable;

public:

    GraceBoolean(bool value);

    virtual void dispatch(const std::string &methodName, Evaluator &eval);

    virtual const GraceBoolean &asBoolean() const;

    bool value() const;

    bool operator==(const GraceObject &rhs) const;
    bool operator!=(const GraceObject &rhs) const;

    class PrefixNot : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

};

static const std::shared_ptr<GraceBoolean> GraceTrue = make_obj<GraceBoolean>(true);
static const std::shared_ptr<GraceBoolean> GraceFalse= make_obj<GraceBoolean>(false);

} // end namespace naylang

#endif //NAYLANG_BOOLEANOBJECT_H
