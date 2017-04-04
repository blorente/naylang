//
// Created by borja on 4/1/17.
//

#include <model/evaluators/ASTPrintEvaluator.h>
#include <model/ast/NodeFactory.h>
#include "NaylangParserVisitor.h"

namespace naylang {

antlrcpp::Any NaylangParserVisitor::visitNumber(GraceParser::NumberContext *ctx) {
    assignPartialExp(make_node<NumberLiteral>(std::stod(ctx->getText())));
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitPrefix_op(GraceParser::Prefix_opContext *ctx) {
    assignPartialStr("prefix" + ctx->getText());
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitFact(GraceParser::FactContext *ctx) {
    ctx->expressionBase()->accept(this);
    auto reciever = _partialExp;
    if (ctx->prefix_op()) {
        ctx->prefix_op()->accept(this);
        assignPartialExp(make_node<ExplicitRequestNode>(_partialStr, reciever));
    }
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitAtom(GraceParser::AtomContext *ctx) {
    ctx->expressionBase()->accept(this);
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitExpressionBase(GraceParser::ExpressionBaseContext *ctx) {
    ctx->number()->accept(this);
    return 0;
}

const StatementPtr NaylangParserVisitor::AST() const {
    return _tree;
}

void NaylangParserVisitor::assignPartialStr(std::string partial) {
    _partialStr = partial;
}

void NaylangParserVisitor::assignPartialExp(ExpressionPtr partial) {
    _partialExp = partial;
    _tree = _partialExp;
}

void NaylangParserVisitor::assignPartialStat(StatementPtr partial) {
    _partialStat = partial;
    _tree = _partialStat;
}

antlrcpp::Any NaylangParserVisitor::defaultResult() {
    return 0;
}
}