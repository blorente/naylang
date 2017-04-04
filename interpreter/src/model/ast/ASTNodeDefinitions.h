//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef ANTLR4CPP_FETCHER_ASTNODEDEFINITIONS_H
#define ANTLR4CPP_FETCHER_ASTNODEDEFINITIONS_H

#include <model/ast/Statement.h>

#include <model/ast/control/IfThen.h>
#include <model/ast/control/IfThenElse.h>
#include <model/ast/control/While.h>

#include <model/ast/declarations/Declaration.h>
#include <model/ast/declarations/ConstantDeclaration.h>
#include <model/ast/declarations/MethodDeclaration.h>
#include <model/ast/declarations/VariableDeclaration.h>

#include <model/ast/expressions/Block.h>
#include <model/ast/expressions/Lineup.h>
#include <model/ast/expressions/ObjectConstructor.h>
#include <model/ast/expressions/VariableReference.h>
#include <model/ast/expressions/primitives/BooleanLiteral.h>
#include <model/ast/expressions/primitives/NumberLiteral.h>
#include <model/ast/expressions/primitives/StringLiteral.h>
#include <model/ast/expressions/primitives/CharLiteral.h>
#include <model/ast/expressions/requests/ImplicitRequestNode.h>
#include <model/ast/expressions/requests/ExplicitRequestNode.h>

#endif //ANTLR4CPP_FETCHER_ASTNODEDEFINITIONS_H
