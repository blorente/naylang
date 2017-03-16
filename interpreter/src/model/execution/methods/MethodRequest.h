//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_METHODREQUEST_H
#define NAYLANG_METHODREQUEST_H

#include <string>
#include <vector>
#include <model/execution/objects/GraceObject.h>

namespace naylang {

class MethodRequest {

    std::string _name;
    std::vector<GraceObjectPtr> _params;

public:
    MethodRequest(const std::string &name);
    MethodRequest(const std::string &name, std::vector<GraceObjectPtr> params);

    const std::string &name() const;

    const std::vector<GraceObjectPtr> &params() const;
};
} // end namespace naylang

#endif //NAYLANG_METHODREQUEST_H
