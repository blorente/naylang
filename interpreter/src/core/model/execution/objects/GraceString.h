//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_GRACESTRING_H
#define NAYLANG_GRACESTRING_H

#include <core/model/execution/methods/NativeMethod.h>
#include "GraceObject.h"

namespace naylang {

class GraceString : public GraceObject {

    std::string _value;

public:
    GraceString(const std::string &value);

    virtual void addDefaultMethods();

    virtual const GraceString &asString() const;

    const std::string &value() const;

    std::string prettyPrint(int indentLevel) override;

    class Equals : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class NotEquals : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class Greater : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class GreaterEq : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class Less : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class LessEq : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class Concat : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class At : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class Substring : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class AsString : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

};
} // end namespace naylang

#endif //NAYLANG_GRACESTRING_H
