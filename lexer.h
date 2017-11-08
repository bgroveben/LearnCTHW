/*
* https://en.wikipedia.org/wiki/Lexical_analysis
* A lexer, also known as a tokenizer, forms the first phase of a compiler
* frontend in modern processing.
* The tokenizer is responsible for dividing the input stream into individual
* tokens, identifying the token type, and passing tokens one at a time to the
* next stage of the compiler.
*/
/*********************************************************
* https://github.com/timpeskett/c-lex/blob/master/lexer.h
* This is the module that performs the file I/O and defines the C regular
* expressions.
* In theory, this module and the symtable module could be changed to build a
* lexical analyser for a different language.
*********************************************************/

#ifndef LEXER_H
#define LEXER_H

#include "global.h"
#include "nfa.h"
#include "symtable.h"
#include "Symbol.h"
#include "regex.h"

#define BUF SIZE 1024

void lexerInit(void);

Bool lexerOpenFile( char *fName);

Symbol lexerNextTok( void );

void lexerCloseFile( void );

void lexerDestroy( void );



#endif