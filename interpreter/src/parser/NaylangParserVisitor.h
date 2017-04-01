//
// Created by borja on 4/1/17.
//

#ifndef NAYLANGPARSERLISTENER_H
#define NAYLANGPARSERLISTENER_H

#include "GraceParserBaseVisitor.h"
#include <memory>

#include <model/ast/Statement.h>
#include <model/ast/expressions/Expression.h>

#include <model/ast/expressions/primitives/BooleanLiteral.h>
#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/expressions/primitives/StringLiteral.h>
#include <model/ast/expressions/requests/ExplicitRequestNode.h>

namespace naylang {
class NaylangParserVisitor : public GraceParserBaseVisitor {

    StatementPtr _tree;
    StatementPtr _partialStat;
    ExpressionPtr _partialExp;
    std::string _partialStr;

public:
    typedef GraceParserBaseVisitor super;

    const StatementPtr AST() const;

    antlrcpp::Any visitFact(GraceParser::FactContext *ctx) override;
    antlrcpp::Any visitAtom(GraceParser::AtomContext *ctx) override;
    antlrcpp::Any visitExpressionBase(GraceParser::ExpressionBaseContext *ctx) override;
    antlrcpp::Any visitNumber(GraceParser::NumberContext *ctx) override;
    antlrcpp::Any visitPrefix_op(GraceParser::Prefix_opContext *ctx) override;

private:

    void assignPartialStr(std::string partial);
    void assignPartialExp(ExpressionPtr partial);
    void assignPartialStat(StatementPtr partial);
};
}

#endif //GRACEPARSERLISTENER_H
