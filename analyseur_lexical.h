#ifndef ANAL_LEX
#define ANAL_LEX
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char* keywords_list[];
extern const char* specialTokens_list[];
extern const char* specialTokens_symb[];
int keywords_list_size;
int specialTokens_list_size;
int testguill;
int nbreguill;
#define MAXDIGIT 11
#define MAXCHAR 20
#define NBRKEYWORDS keywords_list_size
#define NBRSPECIALTOKENS specialTokens_list_size
#define lenValue 20
#define lenName 20
/**Boolean**/
typedef enum{FALSE, TRUE} boolean;
/**File**/
FILE* program ;
/**TOKEN**/
typedef struct{
    char name[lenName];
    char value[lenValue];
} Token;
/**Declaration**/
char currentChar;
Token currentToken;
char NextChar();
void LexError();
Token getToken();
void ignoreWhiteSpaces();
boolean isNumber();
boolean isWord();
boolean isSpecial();

#endif
