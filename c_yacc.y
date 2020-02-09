%{
    #include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
%}

%token SUB ADD MUL DIV MOD SADD SSUB SMUL SDIV SMOD INC DEC
%token GT LT NE GE LE EQ ASSIGN
%token AND OR NOT
%token IF ELSE ELSEIF FOR WHILE
%token BREAK
%token INT CHAR FLOAT STATIC
%token ID numconst
%token delimiter COMMA
%token OP CP OB CB OS CS

%start program

%%
program: declarationList;
declarationList: declarationList declaration
    | declaration;
declaration: varDeclaration
    | funDeclaration;
varDeclaration: typeSpecifier varDeclList delimiter;
scopedVarDeclaration: scopedTypeSpecifier varDeclList delimiter;
varDeclList: varDeclList varDeclInitialize | varDeclInitialize;
varDeclInitialize: varDeclId
    | varDeclId: simpleExpression;
varDeclId: ID
    | ID OS numconst CS;
scopedTypeSpecifier: static typeSpecifier
    | typeSpecifier;
typeSpecifier: INT
    | CHAR
    | FLOAT;
funDeclaration: typeSpecifier ID OP params CP statement
    | ID OP params CP statement;
params: paramList | ;
paramList: paramList delimiter paramTypeList
    | paramTypeList;
paramTypeList: typeSpecifier paramIdList;
paramIdList: paramIdList, paramId
    | paramId;
paramId: ID
    | ID OS CS;
statement: expressionStmt
    | compoundStmt
    | selectionStmt
    | iterationStmt
    | returnStmt
    | breakStmtexpressionStmt: expression delimiter
    | delimiter;
compoundStmt: OB localDeclarations statementList CB;
localDeclarations: localDeclarations scopedVarDeclaration | ;
statementList: statementList statement | ;
elsifList: elsifList ELSEIF simpleExpression then statement | ;
selectionStmt: IF simpleExpression then statement elsifList
    | IF simpleExpression then statement elsifList ELSE statement
iterationRange: ID = simpleExpression…simpleExpression
    | ID = simpleExpression…simpleExpression: simpleExpression;
iterationStmt: WHILE OP simpleExpression CP do statement
    | FOR OP varDeclInitialize delimiter simpleExpression delimiter expression CP do statement
    | FOR OP delimiter simpleExpression delimiter expression CP do statement
    | FOR OP varDeclInitialize delimiter simpleExpression delimiter  CP do statement
    | FOR OP delimiter  simpleExpression delimiter CP do statement
    | FOR OP delimiter  delimiter CP do statement;
returnStmt: return delimiter
    | return expression delimiter;
breakStmt: BREAK delimiter;

expression: mutable ASSIGN expression
    | mutable SADD expression
    | mutable SSUB expression
    | mutable SMUL expression
    | mutable SDIV expression
    | mutable SMOD expression
    | mutable INC
    | mutable DEC
    | simpleExpression;
simpleExpression: simpleExpression OR andExpression
    | andExpression;
andExpression: andExpression AND unaryRelExpression
    | unaryRelExpression;
unaryRelExpression: NOT unaryRelExpression
    | relExpression;
relExpression: sumExpression relop sumExpression
    | sumExpression;
relop: LE
    | LT
    | GT
    | GE
    | EQ
    | NE;
sumExpression: sumExpression sumop mulExpression
    | mulExpression;
sumop: ADD
    | SUB;
mulExpression: mulExpression mulop unaryExpression
    | unaryExpression;
mulop: MUL
    | DIV
    | MOD;
unaryExpression: unaryop unaryExpression
    | factor;
unaryop: SUB
    | MUL;
factor: immutable
    | mutable;
mutable: ID
    | mutable [expression];
immutable: OP expression CP
    | call
    | constant;
call: ID OP args CP;
args: argList | ;
argList: argList, expression
    | expression;
constant: numconst
    | charconst
    | stringconst
    | true
    | false;
%%