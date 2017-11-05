/*
* https://en.wikipedia.org/wiki/Recursive_descent_parser#C_implementation
* 
* Parse: Within computational linguistics the term is used to refer to the 
* formal analysis by a computer of a sentence or other string of words into 
* its constituents, resulting in a parse tree showing their syntactic 
* relation to each other, which may also contain semantic and 
* other information.
* - https://en.wikipedia.org/wiki/Parsing
*/

/*
* The following EBNF-like grammar (for Niklaus Wirth's PL/0 programming 
* language, from Algorithms + Data Structures = Programs) is in LL(1) form.
* Terminals are expressed in quotes. 
* Each nonterminal is defined by a rule in the grammar, except for ident and 
* number, which are assumed to be implicitly defined.
*/
/*
 program = block "." .
 
 block =
     ["const" ident "=" number {"," ident "=" number} ";"]
     ["var" ident {"," ident} ";"]
     {"procedure" ident ";" block ";"} statement .
 
 statement =
     ident ":=" expression
     | "call" ident
     | "begin" statement {";" statement } "end"
     | "if" condition "then" statement
     | "while" condition "do" statement .
 
 condition =
     "odd" expression
     | expression ("="|"#"|"<"|"<="|">"|">=") expression .
 
 expression = ["+"|"-"] term {("+"|"-") term} .
 
 term = factor {("*"|"/") factor} .
 
 factor =
     ident
     | number
     | "(" expression ")" .
*/

/*
* What follows is an implementation of a recursive descent parser for the 
* above language in C. 
* The parser reads in source code, and exits with an error message if the code
* fails to parse, exiting silently if the code parses correctly.
* Notice how closely the predictive parser below mirrors the grammar above. 
* There is a procedure for each nonterminal in the grammar. 
* Parsing descends in a top-down manner, until the final nonterminal has been
* processed. 
* The program fragment depends on a global variable, sym, which contains the 
* current symbol from the input, and the function nextsym, which updates sym 
* when called.
* The implementations of the functions nextsym and error are omitted for
* simplicity.
*/