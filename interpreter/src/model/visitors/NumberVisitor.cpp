#include "NumberVisitor.h"

namespace naylang {
void NumberVisitor::process(Expression &exp, Environment &env) {
    Number &number = static_cast<Number &>(exp);
}

}