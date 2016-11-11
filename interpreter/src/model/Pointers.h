#ifndef NAYLANG_POINTERS_H
#define NAYLANG_POINTERS_H

#include <memory>
#include "model/Visitor.h"
#include "model/Expression.h"
#include "model/Environment.h"

namespace naylang {

class Visitor;
class Expression;
class Environment;

typedef std::shared_ptr<Visitor> VisitorPointer;
typedef std::shared_ptr<Expression> ExpressionPointer;
typedef std::shared_ptr<Environment> EnvironmentPointer;

}

#endif //NAYLANG_POINTERS_H
