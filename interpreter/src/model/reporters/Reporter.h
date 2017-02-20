//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_REPORTER_H
#define NAYLANG_REPORTER_H

#include <model/Evaluator.h>

namespace naylang {

class Reporter {
public:
    virtual void report(const std::string &message) = 0;
};

} // end namespace naylang


#endif //NAYLANG_REPORTER_H
