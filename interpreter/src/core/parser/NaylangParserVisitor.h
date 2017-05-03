//
// Copyright (c) 2016 by Borja Lorente.
// Distributed under the GPLv3 license.
//


#ifndef NAYLANG_NAYLANGPARSERLISTENER_H
#define NAYLANG_NAYLANGPARSERLISTENER_H

#include "GraceParserBaseVisitor.h"
#include <memory>

#include <core/model/ast/ASTNodeDefinitions.h>
#include <core/model/ast/GraceAST.h>
#include <core/parser/NaylangParserStack.h>

namespace naylang {

class NaylangParserVisitor : public GraceParserBaseVisitor {

    GraceAST _tree;
    std::vector<std::string> _partialStrs;
    NaylangParserStack _partials;

public:
    typedef GraceParserBaseVisitor super;

    GraceAST AST() const;

    antlrcpp::Any visitProgram(GraceParser::ProgramContext *ctx) override;

    antlrcpp::Any visitSelfAssign(GraceParser::SelfAssignContext *ctx) override;
    antlrcpp::Any visitImplAssign(GraceParser::ImplAssignContext *ctx) override;
    antlrcpp::Any visitExplAssign(GraceParser::ExplAssignContext *ctx) override;

    antlrcpp::Any visitPrefixExp(GraceParser::PrefixExpContext *ctx) override;
    antlrcpp::Any visitPrefix_op(GraceParser::Prefix_opContext *ctx) override;

    antlrcpp::Any visitNumber(GraceParser::NumberContext *ctx) override;
    antlrcpp::Any visitString(GraceParser::StringContext *ctx) override;
    antlrcpp::Any visitBoolean(GraceParser::BooleanContext *ctx) override;

    antlrcpp::Any visitIdentifier(GraceParser::IdentifierContext *ctx) override;

    antlrcpp::Any visitMulDivExp(GraceParser::MulDivExpContext *ctx) override;
    antlrcpp::Any visitAddSubExp(GraceParser::AddSubExpContext *ctx) override;

    antlrcpp::Any visitConstantDeclaration(GraceParser::ConstantDeclarationContext *ctx) override;
    antlrcpp::Any visitVariableDeclaration(GraceParser::VariableDeclarationContext *ctx) override;

    antlrcpp::Any visitUserMethod(GraceParser::UserMethodContext *ctx) override;

    antlrcpp::Any visitPrefixMethod(GraceParser::PrefixMethodContext *ctx) override;

    antlrcpp::Any visitMethodSignature(GraceParser::MethodSignatureContext *ctx) override;
    antlrcpp::Any visitMethodSignaturePart(GraceParser::MethodSignaturePartContext *ctx) override;
    antlrcpp::Any visitFormalParameterList(GraceParser::FormalParameterListContext *ctx) override;
    antlrcpp::Any visitFormalParameter(GraceParser::FormalParameterContext *ctx) override;

    antlrcpp::Any visitMethodBody(GraceParser::MethodBodyContext *ctx) override;

    antlrcpp::Any visitIdentifierImplReq(GraceParser::IdentifierImplReqContext *ctx) override;
    antlrcpp::Any visitOneParamImplReq(GraceParser::OneParamImplReqContext *ctx) override;
    antlrcpp::Any visitMethImplReq(GraceParser::MethImplReqContext *ctx) override;
    antlrcpp::Any visitMultipartRequest(GraceParser::MultipartRequestContext *ctx) override;
    antlrcpp::Any visitMethodRequestPart(GraceParser::MethodRequestPartContext *ctx) override;
    antlrcpp::Any visitEffectiveParameterList(GraceParser::EffectiveParameterListContext *ctx) override;
    antlrcpp::Any visitImplReqExplReq(GraceParser::ImplReqExplReqContext *ctx) override;

    antlrcpp::Any visitObjectConstructor(GraceParser::ObjectConstructorContext *ctx) override;
    antlrcpp::Any visitBlock(GraceParser::BlockContext *ctx) override;
    antlrcpp::Any visitLineup(GraceParser::LineupContext *ctx) override;


private:

    void pushPartialStr(const std::string &partial);
    void pushPartialExp(ExpressionPtr partial);
    void pushPartialStat(StatementPtr partial);
    void pushPartialDecl(DeclarationPtr partial);

    std::vector<std::string> popPartialStrs(int length);
    std::vector<ExpressionPtr> popPartialExps(int length);
    std::vector<StatementPtr> popPartialStats(int length);
    std::vector<DeclarationPtr> popPartialDecls(int length);

    std::string popPartialStr();
    ExpressionPtr popPartialExp();
    StatementPtr popPartialStat();

    void clearPartials();

    antlrcpp::Any defaultResult() override;

    int getLine(const antlr4::ParserRuleContext *ctx) const;
    int getLine(antlr4::tree::TerminalNode *terminal) const;
    int getCol(const antlr4::ParserRuleContext *ctx) const;

    void notifyBreakable(StatementPtr node);

    int getLastLine(const antlr4::ParserRuleContext *ctx) const;
};
}

#endif //GRACEPARSERLISTENER_H
