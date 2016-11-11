#ifndef NAYLANG_CONSTANTVISITOR_H
#define NAYLANG_CONSTANTVISITOR_H

#include "model/Visitor.h"

namespace naylang {

class ConstantVisitor : public Visitor {
public:
    void process(Expression &exp, Environment &env);
};

}

#endif //NAYLANG_CONSTANTVISITOR_H
