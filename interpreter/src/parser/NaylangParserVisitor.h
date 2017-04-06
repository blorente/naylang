//
// Created by borja on 4/1/17.
//

#ifndef NAYLANGPARSERLISTENER_H
#define NAYLANGPARSERLISTENER_H

#include "GraceParserBaseVisitor.h"
#include <memory>

#include <model/ast/ASTNodeDefinitions.h>

namespace naylang {
class NaylangParserVisitor : public GraceParserBaseVisitor {

    StatementPtr _tree;
    std::vector<StatementPtr> _partialStats;
    std::vector<ExpressionPtr> _partialExps;
    std::vector<std::string> _partialStrs;
    std::vector<DeclarationPtr> _partialDecls;

public:
    typedef GraceParserBaseVisitor super;

    const StatementPtr AST() const;

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

protected:
    virtual antlrcpp::Any defaultResult();

private:

    void pushPartialStr(const std::string &partial);
    void pushPartialExp(ExpressionPtr partial);
    void pushPartialStat(StatementPtr partial);
    void pushPartialDecl(DeclarationPtr partial);

    std::vector<std::string> popPartialStrs(int length) const;
    std::vector<ExpressionPtr> popPartialExps(int length) const;
    std::vector<StatementPtr> popPartialStats(int length) const;
    std::vector<DeclarationPtr> popPartialDecls(int length) const;

    std::string popPartialStr();
    ExpressionPtr popPartialExp();

    void clearPartials();
};
}

#endif //GRACEPARSERLISTENER_H
