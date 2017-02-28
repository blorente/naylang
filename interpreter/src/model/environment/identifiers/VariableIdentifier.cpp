//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//


#include "VariableIdentifier.h"
namespace naylang {

std::string naylang::VariableIdentifier::canonName() const {
    return _name;
}

}
