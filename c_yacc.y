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
	#define NO_OF_KEYWORD 11			// denotes no of keywords
	#define LENGTH_OF_KEYWORDS 7	// max length of keyword string
	#define MAX_MEMBER 10			// max number of member in struct
	#define TYPE_LENGTH 6			// length of type int float void ....
	#define MAX_NO_OF_STRUCT 10		// max_no of structure which can be defined in a scope
	#define STRUCT_FLAG 2			// Flag to know struct which is declared
	
	
	/* the start index for the member of nested struct in the parent struct  initialized at nested_struct rule */ 
	int nested_struct_start_index;
	
	// keyword_Array
	char keywords[NO_OF_KEYWORD][LENGTH_OF_KEYWORDS] = {"char","int","float","bool","if","else","elseif","for","while","break","return"};
	int c = 0;
	int scope = NEWSCOPE;
	void yyerror(const char*);
	int yylex();
	
	// used for ternary construct to denote if condition is true or false
	int ternary_flag = 0;
	
	// flag to mark if the varaible is not_defined. Used to decide wheather to push the value in the symbol table or not.
	// 1 => the varaible is not defined.
	int not_defined = 0;
	
	int error = 0;
	struct symbol {
		char name[LIMIT];
		char type[LIMIT];
		char value[LIMIT];
	};
	
	struct struct_data{
		char struct_name[LIMIT];
		char member_type[MAX_MEMBER][TYPE_LENGTH];
		char member_name[MAX_MEMBER][LIMIT];
		int index_to_insert_member;				// to know at which index do we have to insert new member
	};
	
	struct stack_for_symbol_tables{
		int index_to_insert;
		int struct_index_to_insert;
		struct struct_data struct_defined[MAX_NO_OF_STRUCT];
		struct symbol symbol_table[MAX_SYMBOLS];
	}symbol_table_stack[MAX_SCOPE];
	
	/* used if know if struct is used as member to declare a variable of its type
	   1 means used 
	*/
	int struct_reference_used = 0;
	
	int top_stack_for_symbol_tables = -1;
	
	// called to perform all artihmatic operations
	void fun(char *result ,char *arg1,char *arg2,char *arg3);
	
	/* called to push the varaibles in the current scope */
	int push_my(char *type,char *name,char *value,int flag);
	
	// not used yet
	void struct_member_name(char* struct_name,int struct_index_to_insert);
	/* to pop the scope */
	int pop_my();
	
	/* to check if the varaible of current scope is declared or not
	   return value 1 if not else -1; 
	*/
	int search_my(char *name,int flag);
	
	/* to display the current scope */
	void display();
	void display_struct();
	
	void struct_member(char *type,char *name);
	
	
	/*  update the value of of varaible in symbol table by first checking if varaible is defined or not
		if not defined then this function return value -1  */
	int update_variable_value(char *name,char *value);
	
	int add_struct_member_in_symbol_table(char *struct_name);
	
	/*
		to check if the varaibles in an expression are defined or not
		return type is array of varaibles that are not defined.
	*/
	void check(char *arg1,char *arg3);
	
	void coercion(char *type,char *value);
	
	void init_symbol_table();
	
	void write_to_file();

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
program: declarationList 
    | program statement
    | statement
    ;
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
    | varDeclInitialize
    ;
varDeclList_C: varDeclList_C COMMA varDeclInitialize
    | varDeclInitialize
    ;
varDeclList_F: varDeclList_F COMMA varDeclInitialize
    | varDeclInitialize
    ;
varDeclList_B: varDeclList_B COMMA varDeclInitialize
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
    |"True"
    |"False"
    ;
%%

#include "lex.yy.c"

int yywrap(){
    return 1;
}

int yyerror(const char *str){
    printf("error");
    exit(0);
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
    extern FILE *yyin;
    yyin=fopen("input.c","r");
    yyout=fopen("output.txt","w");
    yyparse();
    char symbol_table[100];
    if(err_no==0){
        for(j=0;j<i;j++){
            char val[2];
            val[0]=symbol[j];
            val[1]=type[j];
            symbol_table[j]=*val;
        }
    }
}
