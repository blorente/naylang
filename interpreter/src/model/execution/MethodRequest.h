//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_METHODREQUEST_H
#define NAYLANG_METHODREQUEST_H

#include <string>

namespace naylang {

class MethodRequest {

    std::string _name;

public:
    MethodRequest(const std::string &name);
};
} // end namespace naylang

#endif //NAYLANG_METHODREQUEST_H
