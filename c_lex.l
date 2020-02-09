%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
	#include "y.tab.h"
%}

letter [a-zA-Z]
digit [0-9]

%%
\'[ a-zA-Z0-9]\' return charconst
\"[ a-zA-Z0-9]*\" return stringconst
"-" return SUB;
"+" return ADD;
"*" return MUL;
"/" return DIV;
"%" return MOD
"%=" return SMOD
"+=" return SADD;
"-=" return SSUB;
"*=" return SMUL;
"/=" return SDIV;
"++" return INC;
"--" return DEC;
">" return GT;
"<" return LT;
"!=" return NE;
">=" return GE;
"<=" return LE;
"==" return EQ;
"=" return ASSIGN;
"&&" return AND;
"||" return OR;
"!" return NOT
"if" return IF;
"else" return ELSE;
"elseif" return ELSEIF;
"while" return WHILE;
"for" return FOR;
"break" return BREAK;
"return" return RETURN;
"int" return INT;
"char" return CHAR;
"float" return FLOAT;
"static" return STATIC
{letter}({letter}|{digit})* return ID;
{digit}+  return numconst;
";" return delimiter;
"," return COMMA;
"(" return OP;
")" return CP;
"{" return OB;
"}" return CB;
"[" return OS;
"]" return CS;
. ;
[ \n] ;
%%