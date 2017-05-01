//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_GRACENUMBER_H
#define NAYLANG_GRACENUMBER_H

#include <core/model/execution/objects/GraceObject.h>
#include <core/model/execution/methods/NativeMethod.h>

namespace naylang {

class GraceNumber : public GraceObject {
public:
    GraceNumber(double value);

    virtual const GraceNumber &asNumber() const override;

    virtual void addDefaultMethods() override;

    double value() const;

    std::string prettyPrint(int indentLevel) override;

    GraceObjectPtr createCopy() override;

    class Equals : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class NotEquals : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class Negative : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class Add : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class Sub : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class Mul : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class Div : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class Mod : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

    class Pow : public NativeMethod {
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

    class AsString : public NativeMethod {
    public:
        virtual GraceObjectPtr respond(GraceObject &self, MethodRequest &request);
    };

};
} // end namespace naylang

#endif //NAYLANG_GRACENUMBER_H
