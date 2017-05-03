parser grammar GraceParser;

options {
	tokenVocab = GraceLexer;
}

// These are all supported parser sections:

// Parser file header. Appears at the top in all parser related files. Use e.g. for copyrights.
@parser::header {/* parser/listener/visitor header section */}

// Appears before any #include in h + cpp files.
@parser::preinclude {/* parser precinclude section */}

// Follows directly after the standard #includes in h + cpp files.
@parser::postinclude {
/* parser postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
}

// Directly preceeds the parser class declaration in the h file (e.g. for additional types etc.).
@parser::context {/* parser context section */}

// Appears in the private part of the parser in the h file.
// The function bodies could also appear in the definitions section, but I want to maximize
// Java compatibility, so we can also create a Java parser from this grammar.
// Still, some tweaking is necessary after the Java file generation (e.g. bool -> boolean).
@parser::members {
/* public parser declarations/members section */
bool myAction() { return true; }
bool doesItBlend() { return true; }
void cleanUp() {}
void doInit() {}
void doAfter() {}
}

// Appears in the public part of the parser in the h file.
@parser::declarations {/* private parser declarations section */}

// Appears in line with the other class member definitions in the cpp file.
@parser::definitions {/* parser definitions section */}

// Additionally there are similar sections for (base)listener and (base)visitor files.
@parser::listenerpreinclude {/* listener preinclude section */}
@parser::listenerpostinclude {/* listener postinclude section */}
@parser::listenerdeclarations {/* listener public declarations/members section */}
@parser::listenermembers {/* listener private declarations/members section */}
@parser::listenerdefinitions {/* listener definitions section */}

@parser::baselistenerpreinclude {/* base listener preinclude section */}
@parser::baselistenerpostinclude {/* base listener postinclude section */}
@parser::baselistenerdeclarations {/* base listener public declarations/members section */}
@parser::baselistenermembers {/* base listener private declarations/members section */}
@parser::baselistenerdefinitions {/* base listener definitions section */}

@parser::visitorpreinclude {/* visitor preinclude section */}
@parser::visitorpostinclude {/* visitor postinclude section */}
@parser::visitordeclarations {/* visitor public declarations/members section */}
@parser::visitormembers {/* visitor private declarations/members section */}
@parser::visitordefinitions {/* visitor definitions section */}

@parser::basevisitorpreinclude {/* base visitor preinclude section */}
@parser::basevisitorpostinclude {/* base visitor postinclude section */}
@parser::basevisitordeclarations {/* base visitor public declarations/members section */}
@parser::basevisitormembers {/* base visitor private declarations/members section */}
@parser::basevisitordefinitions {/* base visitor definitions section */}
/*
 * Parser Rules
 */
program: (statement)*;
statement: expression DELIMITER | declaration | assignment; //| control;

assignment : field=identifier VAR_ASSIGN val=expression DELIMITER                       #SelfAssign
           | scope=explicitRequest DOT field=identifier VAR_ASSIGN val=expression DELIMITER   #ExplAssign
           | scope=implicitRequest DOT field=identifier VAR_ASSIGN val=expression DELIMITER   #ImplAssign
           ;

declaration : variableDeclaration
            | constantDeclaration
            | methodDeclaration
            ;

variableDeclaration: VAR identifier (VAR_ASSIGN expression)? DELIMITER;
constantDeclaration: DEF identifier EQUAL expression DELIMITER;
methodDeclaration: prefixMethod
                 | userMethod
                 ;

prefixMethod: METHOD PREFIX (EXCLAMATION | MINUS)  methodBody;
userMethod: METHOD methodSignature methodBody;

methodSignature: methodSignaturePart+;
methodSignaturePart: identifier (OPEN_PAREN formalParameterList CLOSE_PAREN)?;
formalParameterList: formalParameter (COMMA formalParameter)*;
formalParameter: identifier;

methodBody: OPEN_BRACE methodBodyLine* CLOSE_BRACE;
methodBodyLine: variableDeclaration | constantDeclaration | expression DELIMITER; //| control;

// Using left-recursion and implicit operator precendence. ANTLR 4 Reference, page 70
expression  : rec=expression op=(MUL | DIV) param=expression        #MulDivExp
            | rec=expression op=(PLUS | MINUS) param=expression     #AddSubExp
            | explicitRequest                                       #ExplicitReqExp
            | implicitRequest                                       #ImplicitReqExp
            | prefix_op rec=expression                              #PrefixExp
            | rec=expression infix_op param=expression              #InficExp
            | value                                                 #ValueExp
            ;

explicitRequest : rec=implicitRequest DOT req=implicitRequest #ImplReqExplReq
                | rec=value DOT req=implicitRequest           #ValueExplReq
                ;

implicitRequest : multipartRequest              #MethImplReq
                | identifier effectiveParameter #OneParamImplReq // e.g. `print "Hello"`
                | identifier                    #IdentifierImplReq //variables or 0 params methods
                ;
multipartRequest: methodRequestPart+;
methodRequestPart: methodIdentifier OPEN_PAREN effectiveParameterList? CLOSE_PAREN;
effectiveParameterList: effectiveParameter (COMMA effectiveParameter)*;
effectiveParameter: expression;
methodIdentifier: infix_op | identifier | prefix_op;

value   : objectConstructor #ObjConstructorVal
        | block             #BlockVal
        | lineup            #LineupVal
        | primitive         #PrimitiveValue
        ;

objectConstructor: OBJECT OPEN_BRACE (statement)* CLOSE_BRACE;
block: OPEN_BRACE (params=formalParameterList RIGHT_ARROW)? body=methodBodyLine* CLOSE_BRACE;
lineup: OPEN_BRACKET lineupContents? CLOSE_BRACKET;
lineupContents: expression (COMMA expression)*;

primitive   : number
            | boolean
            | string
            ;

identifier: ID;
number: INT;
boolean: TRUE | FALSE;
string: QUOTE content=.*? QUOTE;
prefix_op: MINUS | EXCLAMATION;
infix_op: MOD | POW | CONCAT;

