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

    double _value;

public:
    GraceNumber(double value);

    virtual const GraceNumber &asNumber() const override;

    virtual void addDefaultMethods() override;

    double value() const;

    std::string prettyPrint(int indentLevel) override;

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
        GraceObjectPtr respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) override;
    };

    class Add : public NativeMethod {
    public:
        GraceObjectPtr respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) override;
    };

    class Sub : public NativeMethod {
    public:
        GraceObjectPtr respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) override;
    };

    class Mul : public NativeMethod {
    public:
        GraceObjectPtr respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) override;
    };

    class Div : public NativeMethod {
    public:
        GraceObjectPtr respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) override;
    };

    class Mod : public NativeMethod {
    public:
        GraceObjectPtr respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) override;
    };

    class Pow : public NativeMethod {
    public:
        GraceObjectPtr respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) override;
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
        GraceObjectPtr respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) override;
    };
};
} // end namespace naylang

#endif //NAYLANG_GRACENUMBER_H
