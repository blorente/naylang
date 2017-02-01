//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_GRACEOBJECT_H
#define NAYLANG_GRACEOBJECT_H

#include <model/Expression.h>
#include <model/environment/Environment.h>

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

    std::map<Identifier, GraceObject> _self;

    double _number;
    ExpressionPtr _body;

public:

    GraceObject();
    GraceObject(double number);
    GraceObject(ExpressionPtr body);

    bool isUndefined() const;
    double asNumber() const;
    ExpressionPtr asMethod() const;

    //const std::map<Identifier, GraceObject> & getSelf() const;
    //void addField(const Identifier &name, const GraceObject &value);

    bool operator==(const GraceObject &other) const;
    bool operator!=(const GraceObject &other) const;

};
}


#endif //NAYLANG_GRACEOBJECT_H
