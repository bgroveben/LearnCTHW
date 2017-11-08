/*
* https://en.wikipedia.org/wiki/Lexical_analysis
* A lexer, also known as a tokenizer, forms the first phase of a compiler
* frontend in modern processing.
* The tokenizer is responsible for dividing the input stream into individual
* tokens, identifying the token type, and passing tokens one at a time to the
* next stage of the compiler.
*/
/*********************************************************
* https://github.com/timpeskett/c-lex/blob/master/lexer.c
* This is the module that performs the file I/O and defines the C regular
* expressions.
* In theory, this module and the symtable module could be changed to build a
* lexical analyser for a different language.
*********************************************************/

#include "lexer.h"

static Bool initiated = false;
static struct 
{
	char *regexp;
	Token tok;
	Dfa dfa;
} dfaInfo[] = {
	{ "(\\ |\\t|\\n)", WHITESPACE, NULL },
	{ "({)", LBRACE, NULL },
	{ "(})", RBRACE, NULL },
	{ "([)", LSQUARE, NULL },
	{ "(])", RSQUARE, NULL },
	{ "(\\()", LPAREN, NULL },
	{ "(\\))", RPAREN, NULL },
	{ "(\\*|/|%)", MULTOP, NULL },
	{ "(+|-)", ADDOP, NULL },
	{ "(<<|>>)", SHIFTOP, NULL },
	{ "(<|>|<=|>=)", RELOP, NULL },
	{ "(==|!=)", EQOP, NULL },
	{ "(&)", BITANDOP, NULL },
	{ "(^)", BITEXOROP, NULL },
	{ "(\\|)", BITINOROP, NULL },
	{ "(&&)", LOGANDOP, NULL },
	{ "(\\|\\|)", LOGOROP, NULL },
	{ "(=|\\*=|/=|%=|+=|-=|<<=|>>=|&=|^=|\\|=)", ASSIGN, NULL },
	{ "(++|--)", INCDEC, NULL },
	{ "(.)", DOT, NULL },
	{ "(->)", ARROW, NULL },
	{ "(,)", COMMA, NULL },
	{ "(?)", QUESTION, NULL },
	{ "(:)", COLON, NULL },
	{ "(...)", ELLIPSIS, NULL },
	{ "(;)", SEMICOLON },
	{ "((_|\\l)(\\l|_|\\d)*)", ID, NULL },
	{ "(((1|2|3|4|5|6|7|8|9)(\\d)*)|(0(\\o)*)|(0(x|X)(\\x)(\\x)*))", INTCONST, NULL },
	/* Sorry */
	{ "((\\d\\d*(e|E)(-|+)\\d\\d*)|(\\d\\d*(e|E)\\d\\d*)|(\\d\\d*(e|E)(-|+)\\d\\d*(f|l|F|L))|(\\d\\d*(e|E)\\d\\d*(f|l|F|L))|(\\d\\d*.)|(\\d\\d*.(e|E)\\d\\d*)|(\\d\\d*.(e|E)(+|-)\\d\\d*)|(\\d\\d*.(f|l|F|L))|(\\d\\d*.(e|E)\\d\\d*(f|l|F|L))|(\\d\\d*.(e|E)(+|-)\\d\\d*(f|l|F|L))|(\\d*.\\d\\d*)|(\\d*.\\d\\d*(e|E)\\d\\d*)|(\\d*.\\d\\d*(e|E)(+|-)\\d\\d*)|(\\d*.\\d\\d*(f|l|F|L))|(\\d*.\\d\\d*(e|E)\\d\\d*(f|l|F|L))|(\\d*.\\d\\d*(e|E)(+|-)\\d\\d*(f|l|F|L)))", FLOATCONST, NULL },
	{ "(\"(\\e\"|\\\\\")*\")", STRINGLIT, NULL },
	{ "(('(\\e'|\\\\')*')|(L('(\\e'|\\\\')*')))", CHARCONST, NULL }
};

/* Structure to hold the data about our currently open file: */