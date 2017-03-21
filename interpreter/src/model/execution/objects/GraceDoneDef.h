//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//


#ifndef NAYLANG_GRACEDONEDEF_H
#define NAYLANG_GRACEDONEDEF_H

#include "GraceObject.h"

namespace naylang {

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
} // end namespace naylang

#endif //NAYLANG_GRACEDONEDEF_H
