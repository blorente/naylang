//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#include <core/model/execution/methods/MethodFactory.h>
#include <core/model/evaluators/ExecutionEvaluator.h>
#include "GraceString.h"
#include "GraceBoolean.h"
#include "GraceNumber.h"

namespace naylang {

GraceString::GraceString(const std::string &value) : _value(value) {
    addDefaultMethods();
}

const std::string &GraceString::value() const {
    return _value;
}

void GraceString::addDefaultMethods() {
    _nativeMethods["==(_)"] = make_native<Equals>();
    _nativeMethods["!=(_)"] = make_native<NotEquals>();
    _nativeMethods[">(_)"] = make_native<Greater>();
    _nativeMethods[">=(_)"] = make_native<GreaterEq>();
    _nativeMethods["<(_)"] = make_native<Less>();
    _nativeMethods["<=(_)"] = make_native<LessEq>();
    _nativeMethods["++(_)"] = make_native<Concat>();
    _nativeMethods["at(_)"] = make_native<At>();
    _nativeMethods["substringFrom(_)to(_)"] = make_native<Substring>();
    _nativeMethods["asString"] = make_native<AsString>();
}

const GraceString &GraceString::asString() const {
    return *this;
}

std::string GraceString::prettyPrint(int indentLevel) {
    return std::string{"\"" + _value + "\""};
}

GraceObjectPtr GraceString::Equals::respond(GraceObject &self, MethodRequest &request) {
    if (self.asString().value() == request.params()[0]->asString().value()) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceString::NotEquals::respond(GraceObject &self, MethodRequest &request) {
    if (self.asString().value() != request.params()[0]->asString().value()) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceString::Greater::respond(GraceObject &self, MethodRequest &request) {
    if (self.asString().value().compare(request.params()[0]->asString().value()) > 0) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceString::GreaterEq::respond(GraceObject &self, MethodRequest &request) {
    if (self.asString().value().compare(request.params()[0]->asString().value()) >= 0) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceString::Less::respond(GraceObject &self, MethodRequest &request) {
    if (self.asString().value().compare(request.params()[0]->asString().value()) < 0) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceString::LessEq::respond(GraceObject &self, MethodRequest &request) {
    if (self.asString().value().compare(request.params()[0]->asString().value()) <= 0) {
        return GraceTrue;
    }
    return GraceFalse;
}

GraceObjectPtr GraceString::Concat::respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) {
    std::string val = self.asString().value();
    val.append(request.params()[0]->asString().value());
    return context.create_obj<GraceString>(val);
}

GraceObjectPtr GraceString::At::respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) {
    int index = (int) request.params()[0]->asNumber().value();
    std::string val = self.asString().value().substr(index, 1);
    return context.create_obj<GraceString>(val);
}

GraceObjectPtr GraceString::Substring::respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) {
    int from = (int) request.params()[0]->asNumber().value();
    int to = (int) request.params()[1]->asNumber().value();
    std::string val = self.asString().value().substr(from, to);
    return context.create_obj<GraceString>(val);
}

GraceObjectPtr GraceString::AsString::respond(ExecutionEvaluator &context, GraceObject &self, MethodRequest &request) {
    return context.create_obj<GraceString>(self.asString().value());
}
}