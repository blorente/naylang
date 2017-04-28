//
// Copyright (c) 2017 by Borja Lorente.
// Distributed under the GPLv3 license.
//

#ifndef NAYLANG_ASTNODEDEFINITIONS_H
#define NAYLANG_ASTNODEDEFINITIONS_H

#include <core/model/ast/Statement.h>

#include <core/model/ast/control/IfThen.h>
#include <core/model/ast/control/IfThenElse.h>
#include <core/model/ast/control/While.h>
#include <core/model/ast/control/Return.h>

#include <core/model/ast/declarations/Declaration.h>
#include <core/model/ast/declarations/ConstantDeclaration.h>
#include <core/model/ast/declarations/MethodDeclaration.h>
#include <core/model/ast/declarations/VariableDeclaration.h>

#include <core/model/ast/expressions/Block.h>
#include <core/model/ast/expressions/Lineup.h>
#include <core/model/ast/expressions/ObjectConstructor.h>
#include <core/model/ast/expressions/primitives/BooleanLiteral.h>
#include <core/model/ast/expressions/primitives/NumberLiteral.h>
#include <core/model/ast/expressions/primitives/StringLiteral.h>
#include <core/model/ast/expressions/primitives/CharLiteral.h>
#include <core/model/ast/expressions/requests/ImplicitRequestNode.h>
#include <core/model/ast/expressions/requests/ExplicitRequestNode.h>

#endif //NAYLANG_ASTNODEDEFINITIONS_H
