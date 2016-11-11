#include <model/Expression.h>
#include "Constant.h"

namespace naylang {

const Expression & Constant::value() {
    return *_value;
}

const LValue &Constant::identifier() {
    return _identifier;
}
}