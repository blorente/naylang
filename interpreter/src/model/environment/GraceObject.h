//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_GRACEOBJECT_H
#define NAYLANG_GRACEOBJECT_H


#include <model/Expression.h>

namespace naylang {

class GraceObject {

    bool _undefined = true;
    double _number;
    ExpressionPtr _expression;

public:

    GraceObject() = default;

    bool isDefined();
    void addField(double number);
    void addField(ExpressionPtr expression);
    double value() const;
    //void addMethod();

    bool operator==(const GraceObject &other) const;
    virtual bool operator!=(const GraceObject &other) const;
};
}


#endif //NAYLANG_GRACEOBJECT_H
