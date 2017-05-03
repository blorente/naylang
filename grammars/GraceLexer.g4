lexer grammar GraceLexer;

// These are all supported lexer sections:

// Lexer file header. Appears at the top of h + cpp files. Use e.g. for copyrights.
@lexer::header {/* lexer header section */}

// Appears before any #include in h + cpp files.
@lexer::preinclude {/* lexer precinclude section */}

// Follows directly after the standard #includes in h + cpp files.
@lexer::postinclude {
/* lexer postinclude section */
#ifndef _WIN32
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif
}

// Directly preceds the lexer class declaration in the h file (e.g. for additional types etc.).
@lexer::context {/* lexer context section */}

// Appears in the public part of the lexer in the h file.
@lexer::members {/* public lexer declarations section */
bool canTestFoo() { return true; }
bool isItFoo() { return true; }
bool isItBar() { return true; }

void myFooLexerAction() { /* do something*/ };
void myBarLexerAction() { /* do something*/ };
}

// Appears in the private part of the lexer in the h file.
@lexer::declarations {/* private lexer declarations/members section */}

// Appears in line with the other class member definitions in the cpp file.
@lexer::definitions {/* lexer definitions section */}

//channels { CommentsChannel, DirectiveChannel }

tokens {
	DUMMY
}

WS : [ \r\t\n]+ -> channel(HIDDEN);
INT: Digit+;
Digit: [0-9];

METHOD: 'method ';
VAR_ASSIGN: ':=';
VAR: 'var ';
DEF: 'def ';
PREFIX: 'prefix';
OBJECT: 'object';
IF: 'if';
ELSE: 'else';
WHILE: 'while';

COMMA: ',';
DOT: '.';
DELIMITER: ';';
QUOTE: '"';
EXCLAMATION: '!';
RIGHT_ARROW: '->';
OPEN_PAREN: '(';
CLOSE_PAREN: ')';
OPEN_BRACE: '{';
CLOSE_BRACE: '}';
OPEN_BRACKET: '[';
CLOSE_BRACKET: ']';

CONCAT: '++';
PLUS: '+';
MINUS: '-';
MUL: '*';
DIV: '/';
MOD: '%';
POW: '^';
EQUAL: '=';
LESS: '<';
LESS_EQUAL: '<=';
GREATER: '>';
GREATER_EQUAL: '>=';

TRUE: 'true';
FALSE: 'false';

// SHould be defined last, so that reserved words stay reserved
ID: LETTER (LETTER | '0'..'9')*;
fragment LETTER : [a-zA-Z\u0080-\uFFFF];

