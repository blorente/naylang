//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_GRACEOBJECT_H
#define NAYLANG_GRACEOBJECT_H

#include <model/environment/Environment.h>
#include <model/expressions/ExpressionBlock.h>

namespace naylang {

class Identifier;
class GraceObject;

enum class GraceObjectKind {
    NUMBER,
    METHOD,
    USER,
    UNDEFINED
};

class GraceObject {

    GraceObjectKind _kind;

    double _number;
    ExpressionBlockPtr _body;

public:

    GraceObject();
    GraceObject(double number);
    GraceObject(ExpressionBlockPtr body);

    bool isUndefined() const;
    double asNumber() const;
    ExpressionBlockPtr asMethod() const;

    bool operator==(const GraceObject &other) const;
    bool operator!=(const GraceObject &other) const;

};
}


#endif //NAYLANG_GRACEOBJECT_H
