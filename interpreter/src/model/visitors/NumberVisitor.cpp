#include "NumberVisitor.h"

namespace naylang {
void NumberVisitor::process(Expression &exp) {
    Number &number = dynamic_cast<Number &>(exp);
}
}