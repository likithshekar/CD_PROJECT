%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#define LIMIT 1024
	#define MAX_SYMBOLS 100			// defines max no of record in each symbol table
	#define MAX_SCOPE 10			// defines max no of scopes allowed 
	#define NEWSCOPE 1				// denoted new scope
	#define OLDSCOPE 0				// denotes old scope
	#define NO_OF_KEYWORD 7			// denotes no of keywords
	#define LENGTH_OF_KEYWORDS 7	// max length of keyword string
	#define MAX_MEMBER 10			// max number of member in struct
	#define TYPE_LENGTH 6			// length of type int float void ....
	#define MAX_NO_OF_STRUCT 10		// max_no of structure which can be defined in a scope
	#define STRUCT_FLAG 2			// Flag to know struct which is declared
	
	
	/* the start index for the member of nested struct in the parent struct  initialized at nested_struct rule */ 
	int nested_struct_start_index;
	
	// keyword_Array
	char keywords[NO_OF_KEYWORD][LENGTH_OF_KEYWORDS] = {"char","int","float","void","main","for","struct"};
	int c = 0;
	int scope = NEWSCOPE;
	void yyerror(const char*);
	int yylex();

%}

%right ASSIGN
%left LE GE EQ NE LT GT
%left ADD SUB
%left MUL DIV
%left AND OR
%right NOT

%token charconst stringconst
%token MOD SADD SSUB SMUL SDIV SMOD INC DEC
%token IF ELSE ELSEIF FOR WHILE
%token BREAK RETURN
%token INT CHAR FLOAT BOOL
%token ID numconst
%token delimiter SEMI COMMA NL
%token OP CP OB CB OS CS

%start program

%%
program: declarationList;
declarationList: declarationList varDeclaration
    | varDeclaration
    ;
varDeclaration: INT varDeclList_I delimiter
    | CHAR varDeclList_C delimiter
    | FLOAT varDeclList_F delimiter
    | BOOL varDeclList_B delimiter
    ;
scopedVarDeclaration: INT varDeclList_I delimiter
    | CHAR varDeclList_C delimiter
    | FLOAT varDeclList_F delimiter
    | BOOL varDeclList_B delimiter
    ;
varDeclList_I: varDeclList_I COMMA varDeclInitialize
    {strcpy(temp,(char *)$3); insert(0);}
    | varDeclInitialize
    ;
varDeclList_C: varDeclList_C COMMA varDeclInitialize
    {strcpy(temp,(char *)$3); insert(1);}
    | varDeclInitialize
    ;
varDeclList_F: varDeclList_F COMMA varDeclInitialize
    {strcpy(temp,(char *)$3); insert(2);}
    | varDeclInitialize
    ;
varDeclList_B: varDeclList_B COMMA varDeclInitialize
    {strcpy(temp,(char *)$3); insert(3);}
    | varDeclInitialize
    ;
varDeclInitialize: ID
    | ID ASSIGN simpleExpression
    ;
statement: expressionStmt
    | compoundStmt
    | selectionStmt
    | iterationStmt
    | returnStmt
    | breakStmt
    ;
expressionStmt: expression delimiter
    | delimiter
    ;
compoundStmt: OB localDeclarations statementList CB;
localDeclarations: localDeclarations scopedVarDeclaration
    |
    ;
statementList: statementList statement
    |
    ;
elsifList: elsifList ELSEIF simpleExpression statement
    |
    ;
selectionStmt: IF simpleExpression statement elsifList
    | IF simpleExpression statement elsifList ELSE statement
    ;
iterationStmt: WHILE OP simpleExpression CP statement
    | FOR OP varDeclInitialize delimiter simpleExpression delimiter expression CP statement
    | FOR OP delimiter simpleExpression delimiter expression CP statement
    | FOR OP varDeclInitialize delimiter simpleExpression delimiter CP statement
    | FOR OP delimiter simpleExpression delimiter CP statement
    | FOR OP delimiter delimiter CP statement
    ;
returnStmt: RETURN delimiter
    | RETURN expression delimiter
    ;
breakStmt: BREAK delimiter;
expression: mutable ASSIGN expression
    | mutable SADD expression
    | mutable SSUB expression
    | mutable SMUL expression
    | mutable SDIV expression
    | mutable SMOD expression
    | mutable INC
    | mutable DEC
    | simpleExpression
    ;
simpleExpression: simpleExpression OR andExpression
    | andExpression
    ;
andExpression: andExpression AND unaryRelExpression
    | unaryRelExpression
    ;
unaryRelExpression: NOT unaryRelExpression
    | relExpression
    ;
relExpression: sumExpression relop sumExpression
    | sumExpression
    ;
relop: LE
    | LT
    | GT
    | GE
    | EQ
    | NE
    ;
sumExpression: sumExpression sumop mulExpression
    | mulExpression
    ;
sumop: ADD
    | SUB
    ;
mulExpression: mulExpression mulop unaryExpression
    | unaryExpression
    ;
mulop: MUL
    | DIV
    | MOD
    ;
unaryExpression: unaryop unaryExpression
    | factor
    ;
unaryop: SUB
    | MUL
    ;
factor: immutable
    | mutable
    ;
mutable: ID
    | mutable OS expression CS
    ;
immutable: OP expression CP
    | call
    | constant
    ;
call: ID OP args CP;
args: argList
    |
    ;
argList: argList COMMA expression
    | expression
    ;
constant: numconst
    | charconst
    | stringconst
    |'true'
    |'false'
    ;
%%

#include "lex.yy.c"

int yywrap(){
    return 1;
}

void yyerror(const char *str){
    printf("error");
}

void insert(int type1){
    fl=0;
    for(j=0;j<i;j++){
        if(strcmp(temp,symbol[j])==0){
            if(type[i]==type1)
                printf("Redeclaration of variable");
            else
                printf("Multiple Declaration of Variable");
                err_no=1;
            fl=1;
        }
    }
    if(fl==0){
        type[i]=type1;
        strcpy(symbol[i],temp);
        i++;
    }
}

int main(){
    yyin=fopen("input.c","r");
    yyout=fopen("output.txt","w");
    yyparse();
    if(err_no==0){
        char symbol_table[100];
        for(j=0;j<i;j++){
            char val[2];
            val[0]=symbol[j];
            val[1]=type[j];
            symbol_table[j]=val;
        }
    }
}
