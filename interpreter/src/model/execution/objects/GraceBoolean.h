//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//


#ifndef NAYLANG_BOOLEANOBJECT_H
#define NAYLANG_BOOLEANOBJECT_H

#include <model/execution/objects/GraceObject.h>
#include <map>
#include <model/ast/NodeFactory.h>
#include "Method.h"

namespace naylang {

class GraceBoolean : public GraceObject {

    bool _value;
    std::map<std::string, MethodPtr> _methodTable;

public:

    GraceBoolean(bool value);

    virtual void dispatch(const std::string &methodName, Evaluator &eval);

    virtual const GraceBoolean &asBoolean() const;

    bool value() const;

private:
};

} // end namespace naylang

#endif //NAYLANG_BOOLEANOBJECT_H
