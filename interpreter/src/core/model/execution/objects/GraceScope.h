//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_GRACESCOPE_H
#define NAYLANG_GRACESCOPE_H

#include <core/model/execution/objects/GraceObject.h>

namespace naylang {

class GraceScope : public GraceObject {

public:
    GraceScope() = default;

    virtual void addDefaultMethods();

    virtual GraceObjectPtr  dispatch(const std::string &methodName, ExecutionEvaluator &eval, const std::vector<GraceObjectPtr> &paramValues);

    virtual bool isScope() const;
};
} // end namespace naylang

#endif //NAYLANG_GRACESCOPE_H
