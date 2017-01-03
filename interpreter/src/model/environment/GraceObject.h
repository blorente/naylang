//
// Copyright (c) 1/2/2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_GRACEOBJECT_H
#define NAYLANG_GRACEOBJECT_H

#include <model/Expression.h>

namespace naylang {

class GraceObject {

    bool _defined;
    double _number;
    bool _isNumber;

public:

    GraceObject();
    GraceObject(double number);

    virtual bool isUndefined() const;
    virtual double asNumber() const;

    bool operator==(const GraceObject &other) const;
    bool operator!=(const GraceObject &other) const;

};
}


#endif //NAYLANG_GRACEOBJECT_H
