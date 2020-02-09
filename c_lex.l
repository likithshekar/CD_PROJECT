%{
	#include<stdio.h>
	#include<stdlib.h>
	#include<malloc.h>
	#include<string.h>
	void insert(char*,char);
	int countentry=0;
	int comment=0;
	int bracketcount=0;
%}

charconst: Any single character placed inside single quotes.;
stringconst: Zero or more characters placed inside double quotes.;

letter [a-zA-Z]
digit [0-9]
letdig letter|digit

letter [a-zA-Z]
digit [0-9]

%%
"-" return SUB;
"+" return ADD;
"*" return MUL;
"/" return DIV;
">=" return GE;
"<=" return LE;
"==" return EQ;
"=" return ASSIGN;
"&&" return AND;
"||" return OR;
"^" return XOR;
"if" return IF;
"else" return ELSE;
"break" return BREAK;
"char" return CHAR;
"int" return INT;
"while" return WHILE;
"float" return FLOAT;
"double" return DOUBLE; 
{letter}({letter}|{digit})* return ID;
{digit}+  return numconst;
";" return delimiter;
"," return COMMA;
"(" return OP;
")" return CP;
"{" return OB;
"}" return CB;
. ;
[ \n] ;
%%
