//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//




#include "UserObject.h"

namespace naylang {

void UserObject::addDefaultMethods() {
    GraceObject::addDefaultMethods();
}

GraceObjectPtr UserObject::createCopy() {
    auto obj = make_obj<UserObject>();
    obj->_cell = _cell.clone();
    return std::move(obj);
}
}