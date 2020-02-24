%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include "y.tab.h"

	int x=0;

	extern void yyerror(const char *);  /* prints grammar violation message */

	extern int sym_type(const char *);  /* returns type from symbol table */

	#define sym_type(identifier) IDENTIFIER /* with no symbol table, fake it */

	static void comment(void);

	static int check_type(void);
	
	int line = 0;

%}

letter [a-zA-Z_]
digit [0-9]
A [a-zA-Z_0-9]
WS [ \t\v\n\f]


%option yylineno

%%
	/* Data Types */
int		{ strcpy(yylval.string,yytext); return(INT); }
float		{ strcpy(yylval.string,yytext); return(FLOAT); }
char		{ strcpy(yylval.string,yytext); return(CHAR); }
_bool		{ strcpy(yylval.string,yytext); return(BOOL); }

	/* Headers */
"#"		{ return HASH; }
include		{ return INCLUDE; }
define		{ return DEFINE; }

	/* C Libraries */
"math.h"	{ return MATH; }
"stdio.h"	{ return STDIO; }
"stdlib.h"	{ return STDLIB; }
"string.h"	{ return STRING; }
"time.h"	{ return TIME; }

	/* Control Structures */
for		{ return(FOR); }
if		{ return(FOR); }
else		{ return(ELSE); }
elseif		{ return (ELSEIF); }
while		{ return(WHILE); }
break		{ return(BREAK); }
return		{ return(RETURN); }

	/* User Defined Data Types, Identifiers */
{letter}{A}*			{ strcpy(yylval.string,yytext); return(ID);}
{digit}+			{ strcpy(yylval.string,yytext); return(numconst);}
\"{A}+(".h"|".c")\"		{ return(HEADER_LITERAL);}
Letter?\"(\\.|[^\\"])*\"	{ return(STRING_LITERAL);}

	/* Assignment Operators */
"+="		{return(SADD); }
"-="		{return(SSUB); }
\%\=		{return(SMOD); }
\*\=		{return(SMUL); }
\/\=		{return(SDIV); }

	/* Relational Operators */
"++"		{return(INC); }
"--"		{return(DEC); }
"<="		{ strcpy(yylval.string,yytext); return(LE); }
">="		{ strcpy(yylval.string,yytext); return(GE); }
"=="		{ strcpy(yylval.string,yytext); return(EQ); }
"!="		{ strcpy(yylval.string,yytext); return(NE); }

	/* Basic Syntax */
";"		{return(delimiter); }
"{"		{return(OB); }
"}"		{return(CB); }
","		{return(COMMA); }
":"		{return(SEMI); }
"="		{return(ASSIGN); }
"("		{return(OP); }
")"		{return(CP); }
("[")		{return(OS); }
("]")		{return(CS); }
"-"		{ strcpy(yylval.string,yytext);return(SUB); }
"+"		{ strcpy(yylval.string,yytext);return(ADD); }
"*"		{ strcpy(yylval.string,yytext);return(MUL); }
"/"		{ strcpy(yylval.string,yytext);return(DIV); }
"%"		{ strcpy(yylval.string,yytext);return(MOD); }
"<"		{ strcpy(yylval.string,yytext);return(LT); }
">"		{ strcpy(yylval.string,yytext);return(GT); }
\&\&		{return AND; }
\|\|		{return OR; }
\!		{return NOT; }
[\n]		{yylval.ival=line++;}
{WS}+		{;}
\'.\'		{return charconst;}
\".*\"		{return stringconst;}
%%

int yywrap(void)
{
	return 1;
}


static void comment(void)
{
    int c;

    while ((c = input()) != 0)
        if (c == '*')
        {
            while ((c = input()) == '*')
                ;

            if (c == '/')
                return;

            if (c == 0)
                break;
        }
    yyerror("unterminated comment");
}


