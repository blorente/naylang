#ifndef NAYLANG_VISITOR_H
#define NAYLANG_VISITOR_H

#include "model/Environment.h"
#include "model/Expression.h"

namespace naylang {

class Environment;

class Visitor {
public:
    Visitor() = default;
    virtual ~Visitor() = default;
    virtual void process(Expression &exp, Environment &env) = 0;
};
}


#endif //NAYLANG_VISITOR_H
