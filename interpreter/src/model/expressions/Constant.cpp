#include <model/Expression.h>
#include "Constant.h"

namespace naylang {

void Constant::accept(Visitor &visitor) {
    visitor.process(*this);
}

const Expression & Constant::value() {
    return _value;
}
}