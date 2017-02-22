//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include "Identifier.h"

namespace naylang {

bool Identifier::operator<(const Identifier &other) const  {
    return other.canonName() < canonName();
}

bool Identifier::operator==(const Identifier &other) const {
    return other.canonName() == canonName();
}

bool Identifier::operator!=(const Identifier &other) const {
    return !(other == *this);
}

}