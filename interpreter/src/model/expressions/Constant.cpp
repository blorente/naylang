#include <model/Expression.h>
#include "Constant.h"

namespace naylang {

const Expression & Constant::value() {
    return *_value;
}
}