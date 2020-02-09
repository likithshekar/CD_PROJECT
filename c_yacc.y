%{
    #include<stdio.h>
	#include<stdlib.h>
	#include<string.h>
%}


%start program

%%
program: declarationList;
declarationList: declarationList declaration
    | declaration;
declaration: varDeclaration
    | funDeclaration;
varDeclaration: typeSpecifier varDeclListdelimiter;
scopedVarDeclaration: scopedTypeSpecifier varDeclListdelimiter;
varDeclList: varDeclList varDeclInitialize | varDeclInitialize;
varDeclInitialize: varDeclId
    | varDeclId: simpleExpression;
varDeclId: ID
    | ID [numconst];
scopedTypeSpecifier: static typeSpecifier
    | typeSpecifier;
typeSpecifier: int
    | bool
    | char;
funDeclaration: typeSpecifier ID (params) statement
    | ID (params) statement;
params: paramList | ;
paramList: paramListdelimiter paramTypeList
    | paramTypeList;
paramTypeList: typeSpecifier paramIdList;
paramIdList: paramIdList, paramId
    | paramId;
paramId: ID
    | ID [];
statement: expressionStmt
    | compoundStmt
    | selectionStmt
    | iterationStmt
    | returnStmt
    | breakStmtexpressionStmt: expressiondelimiter
    | delimiter;
compoundStmt: {localDeclarations statementList};
localDeclarations: localDeclarations scopedVarDeclaration | ;
statementList: statementList statement | ;
elsifList: elsifList elsif simpleExpression then statement | ;
selectionStmt: if simpleExpression then statement elsifList
    | if simpleExpression then statement elsifList else statement
iterationRange: ID = simpleExpression…simpleExpression
    | ID = simpleExpression…simpleExpression: simpleExpression;
iterationStmt: while ( simpleExpression ) do statement
    | for ( varDeclInitialize delimiter simpleExpression delimiter expression ) do statement
    | for ( delimiter simpleExpression delimiter expression ) do statement
    | for ( varDeclInitialize delimiter simpleExpression delimiter  ) do statement
    | for ( delimiter  simpleExpression delimiter ) do statement
    | for ( delimiter  delimiter ) do statement;
returnStmt: return delimiter
    | return expression delimiter;
breakStmt: break delimiter;

expression: mutable = expression
    | mutable += expression
    | mutable −= expression
    | mutable ∗= expression
    | mutable /= expression
    | mutable ++
    | mutable −−
    | simpleExpression;
simpleExpression: simpleExpression or andExpression
    | andExpression;
andExpression: andExpression and unaryRelExpression
    | unaryRelExpression;
unaryRelExpression: not unaryRelExpression
    | relExpression;
relExpression: sumExpression relop sumExpression
    | sumExpression;
relop: <=
    | <
    | >
    | >=
    | ==
    |! =;
sumExpression: sumExpression sumop mulExpression
    | mulExpression;
sumop: +
    | −;
mulExpression: mulExpression mulop unaryExpression
    | unaryExpression;
mulop: ∗
    | /
    | %;
unaryExpression: unaryop unaryExpression
    | factor;
unaryop: −
    | ∗
    |?;
factor: immutable
    | mutable;
mutable: ID
    | mutable [expression];
immutable: (expression)
    | call
    | constant;
call: ID (args);
args: argList | ;
argList: argList, expression
    | expression;
constant: numconst
    | charconst
    | stringconst
    | true
    | false;
%%