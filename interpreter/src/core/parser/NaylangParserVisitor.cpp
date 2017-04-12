//
// Created by borja on 4/1/17.
//

#include <core/model/evaluators/ASTPrintEvaluator.h>
#include <core/model/ast/NodeFactory.h>
#include "NaylangParserVisitor.h"

namespace naylang {

GraceAST NaylangParserVisitor::AST() const {
    return _tree;
}

void NaylangParserVisitor::pushPartialStr(const std::string &partial) {
    _partialStrs.push_back(partial);
}

void NaylangParserVisitor::pushPartialExp(ExpressionPtr partial) {
    pushPartialStat(partial);
}

void NaylangParserVisitor::pushPartialStat(StatementPtr partial) {
    _partials.push(partial);
}

void NaylangParserVisitor::pushPartialDecl(DeclarationPtr partial) {
    pushPartialStat(partial);
}

std::vector<std::string> NaylangParserVisitor::popPartialStrs(int length) {
    return std::vector<std::string>(_partialStrs.end() - length, _partialStrs.end());
}

std::vector<ExpressionPtr> NaylangParserVisitor::popPartialExps(int length) {
    return _partials.pop<Expression>(length);
}

std::vector<StatementPtr> NaylangParserVisitor::popPartialStats(int length) {
    return _partials.pop<Statement>(length);
}

std::vector<DeclarationPtr> NaylangParserVisitor::popPartialDecls(int length) {
    return _partials.pop<Declaration>(length);
}

ExpressionPtr NaylangParserVisitor::popPartialExp() {
    return _partials.pop<Expression>();
}

std::string NaylangParserVisitor::popPartialStr() {
    auto ret = (std::basic_string<char, std::char_traits<char>, std::allocator<char>> &&) _partialStrs.back();
    _partialStrs.pop_back();
    return ret;
}

StatementPtr NaylangParserVisitor::popPartialStat() {
    return _partials.pop<Statement>();
}

void NaylangParserVisitor::clearPartials() {
    _partials.clear();
    _partialStrs.clear();
}

antlrcpp::Any NaylangParserVisitor::defaultResult() {
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitPrefix_op(GraceParser::Prefix_opContext *ctx) {
    pushPartialStr("prefix" + ctx->getText());
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitPrefixExp(GraceParser::PrefixExpContext *ctx) {
    ctx->prefix_op()->accept(this);
    auto opname = popPartialStr();
    ctx->rec->accept(this);
    auto rec = popPartialExp();
    pushPartialExp(make_node<ExplicitRequestNode>(opname, rec, getLine(ctx), getCol(ctx)));
    return 0;
}


antlrcpp::Any NaylangParserVisitor::visitNumber(GraceParser::NumberContext *ctx) {
    pushPartialExp(make_node<NumberLiteral>(std::stod(ctx->getText()), getLine(ctx), getCol(ctx)));
    return 0;
}
antlrcpp::Any NaylangParserVisitor::visitMulDivExp(GraceParser::MulDivExpContext *ctx) {
    ctx->rec->accept(this);
    auto reciever = popPartialExp();
    ctx->param->accept(this);
    auto param = popPartialExp();
    auto op = ctx->op->getText() + "(_)";
    std::vector<ExpressionPtr> params{param};
    pushPartialExp(make_node<ExplicitRequestNode>(op, reciever, params, getLine(ctx), getCol(ctx)));
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitAddSubExp(GraceParser::AddSubExpContext *ctx) {
    ctx->rec->accept(this);
    auto reciever = popPartialExp();
    ctx->param->accept(this);
    auto param = popPartialExp();
    auto op = ctx->op->getText() + "(_)";
    std::vector<ExpressionPtr> params{param};
    pushPartialExp(make_node<ExplicitRequestNode>(op, reciever, params, getLine(ctx), getCol(ctx)));
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitString(GraceParser::StringContext *ctx) {
    auto contents = ctx->content->getText();
    pushPartialExp(make_node<StringLiteral>(contents, getLine(ctx), getCol(ctx)));
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitBoolean(GraceParser::BooleanContext *ctx) {
    bool value = ctx->TRUE() != nullptr;
    pushPartialExp(make_node<BooleanLiteral>(value, getLine(ctx), getCol(ctx)));
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitConstantDeclaration(GraceParser::ConstantDeclarationContext *ctx) {
    ctx->identifier()->accept(this);
    auto name = popPartialStr();
    ctx->expression()->accept(this);
    auto value = popPartialExp();
    pushPartialDecl(make_node<ConstantDeclaration>(name, value, getLine(ctx), getCol(ctx)));
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitIdentifier(GraceParser::IdentifierContext *ctx) {
    pushPartialStr(ctx->getText());
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitVariableDeclaration(GraceParser::VariableDeclarationContext *ctx) {
    ctx->identifier()->accept(this);
    auto name = popPartialStr();
    ctx->expression()->accept(this);
    auto value = popPartialExp();
    pushPartialDecl(make_node<VariableDeclaration>(name, value, getLine(ctx), getCol(ctx)));
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitUserMethod(GraceParser::UserMethodContext *ctx) {
    ctx->methodSignature()->accept(this);

    std::string methodName = "";
    for (auto identPart : popPartialStrs(ctx->methodSignature()->methodSignaturePart().size())) {
        methodName += identPart;
    }

    int numParams = 0;
    for (auto part : ctx->methodSignature()->methodSignaturePart()) {
        numParams += part->formalParameterList()->formalParameter().size();
    }
    auto formalParams = popPartialDecls(numParams);

    ctx->methodBody()->accept(this);
    int bodyLength = ctx->methodBody()->methodBodyLine().size();
    auto body = popPartialStats(bodyLength);

    auto methodDeclaration = make_node<MethodDeclaration>(methodName, formalParams, body, getLine(ctx), getCol(ctx));
    pushPartialDecl(methodDeclaration);
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitMethodSignature(GraceParser::MethodSignatureContext *ctx) {
    clearPartials();
    for (auto i : ctx->methodSignaturePart()) {
        i->accept(this);
    }
    return 0;
}
antlrcpp::Any NaylangParserVisitor::visitMethodSignaturePart(GraceParser::MethodSignaturePartContext *ctx) {
    auto partName = ctx->identifier()->getText();
    if (ctx->formalParameterList()->formalParameter().size() != 0) {
        partName += "(";
    }
    for (auto i : ctx->formalParameterList()->formalParameter()) {
        partName += "_,";
    }
    partName.pop_back();
    if (ctx->formalParameterList()->formalParameter().size() != 0) {
        partName += ")";
    }
    pushPartialStr(partName);

    ctx->formalParameterList()->accept(this);
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitFormalParameterList(GraceParser::FormalParameterListContext *ctx) {
    for (auto i : ctx->formalParameter()) {
        i->accept(this);
    }
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitFormalParameter(GraceParser::FormalParameterContext *ctx) {
    pushPartialDecl(make_node<VariableDeclaration>(ctx->identifier()->getText(), getLine(ctx), getCol(ctx)));
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitMethodBody(GraceParser::MethodBodyContext *ctx) {
    for (auto line : ctx->methodBodyLine()) {
        line->accept(this);
    }
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitPrefixMethod(GraceParser::PrefixMethodContext *ctx) {
    std::string methodName = "prefix" + ctx->children[2]->getText();

    std::vector<DeclarationPtr> formalParams;

    std::vector<StatementPtr> body;
    ctx->methodBody()->accept(this);
    int bodyLength = ctx->methodBody()->methodBodyLine().size();
    for (auto line : popPartialStats(bodyLength)) {
        body.push_back(line);
    }

    auto methodDeclaration = make_node<MethodDeclaration>(methodName, formalParams, body, getLine(ctx), getCol(ctx));
    pushPartialDecl(methodDeclaration);
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitIdentifierImplReq(GraceParser::IdentifierImplReqContext *ctx) {
    pushPartialExp(make_node<ImplicitRequestNode>(ctx->getText(), getLine(ctx), getCol(ctx)));
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitOneParamImplReq(GraceParser::OneParamImplReqContext *ctx) {
    auto name = ctx->identifier()->getText() + "(_)";
    ctx->effectiveParameter()->accept(this);
    auto effectiveParam = popPartialExp();
    std::vector<ExpressionPtr> params{effectiveParam};
    pushPartialExp(make_node<ImplicitRequestNode>(name, params, getLine(ctx), getCol(ctx)));
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitMethImplReq(GraceParser::MethImplReqContext *ctx) {
    ctx->multipartRequest()->accept(this);
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitMultipartRequest(GraceParser::MultipartRequestContext *ctx) {
    std::string methodName;
    for (auto part : ctx->methodRequestPart()) {
        part->accept(this);
        methodName += popPartialStr();
    }
    pushPartialStr(methodName);

    int totalParams = 0;
    for (auto part : ctx->methodRequestPart()) {
        totalParams += part->effectiveParameterList()->effectiveParameter().size();
    }

    auto effectiveParams = popPartialExps(totalParams);

    pushPartialExp(make_node<ImplicitRequestNode>(methodName, effectiveParams, getLine(ctx), getCol(ctx)));
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitMethodRequestPart(GraceParser::MethodRequestPartContext *ctx) {
    int params = ctx->effectiveParameterList()->effectiveParameter().size();
    std::string partName = ctx->methodIdentifier()->getText();
    if (params != 0) {
        partName += "(";
    }
    for (int i = 0; i < params; i++) {
        partName += "_,";
    }
    partName.pop_back();
    if (params != 0) {
        partName += ")";
    }
    pushPartialStr(partName);

    ctx->effectiveParameterList()->accept(this);
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitEffectiveParameterList(GraceParser::EffectiveParameterListContext *ctx) {
    for (auto param : ctx->effectiveParameter()) {
        param->accept(this);
    }
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitImplReqExplReq(GraceParser::ImplReqExplReqContext *ctx) {
    ctx->rec->accept(this);
    auto rec = popPartialExp();
    ctx->req->accept(this);
    auto req = static_cast<ImplicitRequestNode &>(*popPartialExp());
    pushPartialExp(make_node<ExplicitRequestNode>(req.identifier(), rec, req.params(), getLine(ctx), getCol(ctx)));
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitObjectConstructor(GraceParser::ObjectConstructorContext *ctx) {
    int statements = ctx->statement().size();
    for (auto stat : ctx->statement()) {
        stat->accept(this);
    }
    auto lines = popPartialStats(statements);
    pushPartialExp(make_node<ObjectConstructor>(lines, getLine(ctx), getCol(ctx)));
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitBlock(GraceParser::BlockContext *ctx) {
    auto block = make_node<Block>(getLine(ctx), getCol(ctx));

    for (auto line : ctx->methodBodyLine()) {
        line->accept(this);
        block->addStatement(popPartialStat());
    }

    std::vector<DeclarationPtr> params;
    if (ctx->params) {
        ctx->params->accept(this);
        params = popPartialDecls(ctx->params->formalParameter().size());
    }
    for (auto param : params) {
        block->addParameter(param);
    }

    pushPartialExp(block);
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitLineup(GraceParser::LineupContext *ctx) {
    int elems = ctx->lineupContents()->expression().size();
    ctx->lineupContents()->accept(this);
    auto content = popPartialExps(elems);
    pushPartialExp(make_node<Lineup>(content, getLine(ctx), getCol(ctx)));
    return 0;
}

antlrcpp::Any NaylangParserVisitor::visitProgram(GraceParser::ProgramContext *ctx) {
    for (auto line : ctx->statement()) {
        clearPartials();
        line->accept(this);
        _tree.push_back(popPartialStat());
    }
    return 0;
}

int NaylangParserVisitor::getCol(const antlr4::ParserRuleContext *ctx) const {
    return ctx->start->getCharPositionInLine();
}

int NaylangParserVisitor::getLine(const antlr4::ParserRuleContext *ctx) const {
    return ctx->start->getLine();
}
}