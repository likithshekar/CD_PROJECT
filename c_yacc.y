%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	#include <ctype.h>
	#define LIMIT 1024
	#define MAX_SYMBOLS 100			// defines max no of record in each symbol table
	#define MAX_SCOPE 10			// defines max no of scopes allowed 
	#define NEWSCOPE 1			// denoted new scope
	#define OLDSCOPE 0			// denotes old scope
	#define NO_OF_KEYWORD 11		// denotes no of keywords
	#define LENGTH_OF_KEYWORDS 7	        // max length of keyword string
	#define MAX_MEMBER 10			// max number of member in struct
	#define TYPE_LENGTH 6			// length of type int float void ....
	#define MAX_NO_OF_STRUCT 10		// max_no of structure which can be defined in a scope
	#define STRUCT_FLAG 2			// Flag to know struct which is declared
	
	
	/* the start index for the member of nested struct in the parent struct  initialized at nested_struct rule */ 
	int nested_struct_start_index;
	
	// keyword_Array
	char keywords[NO_OF_KEYWORD][LENGTH_OF_KEYWORDS] = {"char","int","float","bool","if","else","elseif","for","while","break","return"};
	int c = 0;
	void yyerror(const char*);
	int yylex();
	
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
	
	int top_stack_for_symbol_tables = -1;
	
	// called to perform all artihmatic operations
	void fun(char *result ,char *arg1,char *arg2,char *arg3);
	
	/* called to push the varaibles in the current scope */
	int push_my(char *type,char *name,char *value,int flag);

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

%union
{
	int ival;
	char string[128];
}

%token HASH INCLUDE DEFINE STDIO STDLIB MATH STRING TIME

%token	STRING_LITERAL HEADER_LITERAL

%token charconst stringconst
%token MOD SADD SSUB SMUL SDIV SMOD INC DEC
%token IF ELSE ELSEIF FOR WHILE
%token BREAK RETURN
%token INT CHAR FLOAT BOOL
%token ID numconst
%token delimiter SEMI COMMA NL
%token OP CP OB CB OS CS

%start external

%%
external: s
    | external s
    ;
s: headers
    | program {write_to_file();}
    ;
headers: HASH INCLUDE HEADER_LITERAL
    | HASH INCLUDE LT libraries GT
    ;
libraries: STDIO
    | STDLIB
    | MATH
    | STRING
    | TIME
    ;
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
compoundStmt: OB new_scope localDeclarations statementList CB new_scope_end;
new_scope: {scope = NEWSCOPE;}	
    ;
new_scope_end:{scope = OLDSCOPE;write_to_file();pop_my();}
    ;
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



void yyerror(const char *str)
{
	fflush(stdout);
	fprintf(stderr, "*** %s\n", str);
}
int main(){
	init_symbol_table();
	if(!yyparse())
	{
		printf("Successful\n");
	}
	else
		printf("Unsuccessful\n");

	return 0;
}


void init_symbol_table()
{
	FILE *fptr = fopen("symbol_table.txt","w");
	fclose(fptr);
	FILE *fptr1 = fopen("error.txt","w");
	fclose(fptr1);
	top_stack_for_symbol_tables = 0;
	int *index_to_insert = &symbol_table_stack[top_stack_for_symbol_tables].index_to_insert;
	int i;
	//printf("index_to_insert %d\n",*index_to_insert);
	for(i=0;i<NO_OF_KEYWORD;i++)
	{
		strcpy(symbol_table_stack[top_stack_for_symbol_tables].symbol_table[*index_to_insert].name,keywords[i]);
		//printf("init_symbol_table %s\n",symbol_table_stack[top_stack_for_symbol_tables].symbol_table[*index_to_insert].name);
		strcpy(symbol_table_stack[top_stack_for_symbol_tables].symbol_table[*index_to_insert].type,"KEYWORD");
		strcpy(symbol_table_stack[top_stack_for_symbol_tables].symbol_table[*index_to_insert].value,"");
		//*(index_to_insert)++;
		symbol_table_stack[top_stack_for_symbol_tables].index_to_insert++;
		//printf("hello");
	}
	//display();
	//printf("\n");
	write_to_file();
}

void write_to_file()
{
	FILE *fptr = fopen("symbol_table.txt","a");
	int i = 0;
	if(top_stack_for_symbol_tables != -1)
	{
		int length = symbol_table_stack[top_stack_for_symbol_tables].index_to_insert;
		for(i=0;i<length;i++)
		{
			fprintf(fptr,"TYPE : %5s\t\tNAME : %5s\t\tVALUE : %5s\n",symbol_table_stack[top_stack_for_symbol_tables].symbol_table[i].type,symbol_table_stack[top_stack_for_symbol_tables].symbol_table[i].name,symbol_table_stack[top_stack_for_symbol_tables].symbol_table[i].value);
		}
	}
	fprintf(fptr,"\n");
	fclose(fptr);
}

void struct_member_name(char* struct_name,int struct_index_to_insert)
{
	//printf("In struct_member_name function %s\n",symbol_table_stack[top_stack_for_symbol_tables].struct_defined[struct_index_to_insert].struct_name);
	int index_to_insert_member = symbol_table_stack[top_stack_for_symbol_tables].struct_defined[struct_index_to_insert].index_to_insert_member;
	int i;
	//printf("nested_struct_start_index %d\n",nested_struct_start_index);
	for(i=0;i<index_to_insert_member;i++)
	{
		strcat(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[struct_index_to_insert].member_name[i],".");
		strcat(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[struct_index_to_insert].member_name[i],struct_name);
	}
	//printf("nested struct name %s\n",symbol_table_stack[top_stack_for_symbol_tables].struct_defined[struct_index_to_insert].member_name[i-1]);
}

void coercion(char *type,char *value)
{	
	char buf[6];
	int i=0;
	int is_digit = 1;
	int is_decimal = 0;
	//printf("Type : %s Value : %s\n",type,value);
	while(value[i] != '\0')
	{
		if( isdigit(value[i]) || value[i] == '.')
		{
			if(value[i] == '.')
				is_decimal = 1; 
			//printf("value[%d] : %c\n",i,value[i]);
		}
		else
		{
			is_digit = 0;
			break;
		}
		i++;
	}
	//printf("is_digit : %d\n",is_digit);
	if(!strcmp(type,"int") && is_digit)
	{
		int temp = atoi(value);
		gcvt(temp,6,buf);
		buf[strlen(buf)] = '\0';
		strcpy(value,buf);
		if(is_decimal)
		{
			FILE *fptr = fopen("error.txt","a");
			error = 1;
			fprintf(fptr,"Warning : data loss may occur.Converting float to int\n");
			fclose(fptr);
		}
	}
	else if(!strcmp(type,"float") && is_digit)
	{
		float temp = atof(value);
		gcvt(temp,6,buf);
		buf[strlen(buf)] = '\0';
		strcpy(value,buf);
		//printf("Warning : Converting from int to float'\n");
	}
}
int search_my(char *name,int flag)
{
	//printf("Hello, I'm in search_my()");
	/*
	printf("-------------Inside Search--------------- \n");
	printf("scope %d\n",flag);
	printf("Name %s\n",name);
	printf("index_to_insert %d\n",symbol_table_stack[top_stack_for_symbol_tables].index_to_insert);
	printf("Symbol table's top Varaible Name %s\n",symbol_table_stack[top_stack_for_symbol_tables].symbol_table[0].name);
	printf("-------------Inside Search--------------- \n");
	*/
	if(!flag)
	{
		int length = symbol_table_stack[top_stack_for_symbol_tables].index_to_insert;
		int i = 0;
		while(i<length)
		{
			//printf("stuck here");
			if(!strcmp(name,symbol_table_stack[top_stack_for_symbol_tables].symbol_table[i].name))
				return -1;
			i++;
		}
	}

	return 1;
}

int push_my(char *type,char *name,char *value,int flag)
{
	if(top_stack_for_symbol_tables == MAX_SCOPE)
		printf("Cannot have more than %d Scope in a program",MAX_SCOPE);
	else
	{
		if( top_stack_for_symbol_tables != -1 && strlen(type) != 0 && search_my(name,flag) == -1 )
		//if(0)
		{
			FILE *fptr = fopen("error.txt","a");
			error = 1;
			fprintf(fptr,"Cannot have multiple decleration for same variable %s\n",name);
			fclose(fptr);
			return -1;	
		}
		else
		{
			if(flag == NEWSCOPE)
			{
				top_stack_for_symbol_tables++;
				scope = OLDSCOPE;
			}
			//if(flag != STRUCT_FLAG)
			{
				int index_to_insert = symbol_table_stack[top_stack_for_symbol_tables].index_to_insert;
				if(symbol_table_stack[top_stack_for_symbol_tables].index_to_insert <= MAX_SYMBOLS)
				{
					strcpy(symbol_table_stack[top_stack_for_symbol_tables].symbol_table[index_to_insert].name,name);
					strcpy(symbol_table_stack[top_stack_for_symbol_tables].symbol_table[index_to_insert].type,type);
					/*
					char buf[6];
					if(!strcmp(type,"float"))
					{
						float temp = atof(value);
						char buf[6];
						gcvt(temp,6,buf);
						buf[strlen(buf)] = '\0';
					}
					else if(!strcmp(type,"int"))
					{
						int temp = atoi(value);
						gcvt(temp,6,buf);
						buf[strlen(buf)] = '\0';
					}
					*/
					strcpy(symbol_table_stack[top_stack_for_symbol_tables].symbol_table[index_to_insert].value,value);
					symbol_table_stack[top_stack_for_symbol_tables].index_to_insert += 1;
					//printf("Name %s\n",symbol_table_stack[top_stack_for_symbol_tables].symbol_table[0].name);
					//printf("Value %s\n",symbol_table_stack[top_stack_for_symbol_tables].symbol_table[0].value);
					//printf("Type %s\n",symbol_table_stack[top_stack_for_symbol_tables].symbol_table[0].type);
				}
				else
				{
					printf("Cannot have more than %d Symbols in each scope",MAX_SYMBOLS);
					return -1;
				}
			}
			/*
			else
			{
				
			}
			*/
			return 0;
		}
	}
}

int pop_my()
{
	if(top_stack_for_symbol_tables == -1)
	{
		printf("No Scope Present");
		return -1;
	}
	// poping all the content of top_stack_for_symbol_tables by making corresponding index to zero.
	else
	{
		// setting index_to_insert of top_stack_for_symbol_tables to 0 
		symbol_table_stack[top_stack_for_symbol_tables].index_to_insert = 0;
		
		// setting struct_index_to_insert of top_stack_for_symbol_tables to 0 and also all the index_to_insert_member of struct_defined
		int struct_index_to_insert =  symbol_table_stack[top_stack_for_symbol_tables].struct_index_to_insert;
		int i;
		for(i = 0;i<struct_index_to_insert;i++)
			symbol_table_stack[top_stack_for_symbol_tables].struct_defined[i].index_to_insert_member = 0;
		symbol_table_stack[top_stack_for_symbol_tables].struct_index_to_insert = 0;
		
		// need to clear stack top before decrementing
		top_stack_for_symbol_tables--; 
		return 0;
	}
}

void display_struct()
{
	int i = 0;
	int j;
	if(top_stack_for_symbol_tables != -1)
	{
		int struct_index_to_insert = symbol_table_stack[top_stack_for_symbol_tables].struct_index_to_insert;
		for(i=0;i<struct_index_to_insert;i++)
		{
			//printf("Structure name %s\n",symbol_table_stack[top_stack_for_symbol_tables].struct_defined[i].struct_name);
			int index_to_insert_member = symbol_table_stack[top_stack_for_symbol_tables].struct_defined[i].index_to_insert_member;
			//printf("index_to_insert_member %d\n",index_to_insert_member);
			for(j=0;j<index_to_insert_member;j++)
			{
				printf("Type: %s NAME: %s ",symbol_table_stack[top_stack_for_symbol_tables].struct_defined[i].member_type[j],symbol_table_stack[top_stack_for_symbol_tables].struct_defined[i].member_name[j]);
			}
			printf("\n");
		}
	}
}


void display()
{
	//printf("Display\n");
	int i = 0;
	if(top_stack_for_symbol_tables != -1)
	{
		//printf("Display\n");
		//printf("Display top_stack_for_symbol_tables %d \n",top_stack_for_symbol_tables);
		int length = symbol_table_stack[top_stack_for_symbol_tables].index_to_insert;
		//printf("Display index_to_insert %d \n",length);
		for(i=0;i<length;i++)
		{
			//printf("helllo");
			printf("TYPE : %s\tNAME : %s\tVALUE : %s\n",symbol_table_stack[top_stack_for_symbol_tables].symbol_table[i].type,symbol_table_stack[top_stack_for_symbol_tables].symbol_table[i].name,symbol_table_stack[top_stack_for_symbol_tables].symbol_table[i].value);
		}
	}
}

void fun(char *result ,char *arg1,char *arg2,char *arg3)
{
	/*
	int i = 0;
	int flag = 0;
	if(arg1[i] == '(')
	{
		i+=1;
		flag = 1;
	}
	*/
	int arg1_length = strlen(arg1);
	int arg3_length = strlen(arg3);
	int i=arg1_length-1;
	int j = 0;
	if((isdigit(arg1[i]) | arg1[i] == '.') || (isdigit(arg3[j])  | arg3[j] == '.'))
	{
		float temp; 
		//if(!strcmp(arg2,"*"))
		{
			//printf("result %s arg1 %s arg2 %s arg3 %s\n",result,arg1,arg2,arg3);
			//int arg1_length = strlen(arg1);
			//int arg3_length = strlen(arg3);
			//int i=arg1_length-1;
			//int j = 0;
			while((i >= 0) && (isdigit(arg1[i]) | arg1[i] == '.'))
			{
				//printf("stuck\n");
				i--;
			}
			
			while((j < arg3_length) && (isdigit(arg3[j])  | arg3[j] == '.'))
			{
				//printf("stuck\n");
				j++;
			}
			
			if(i+1 <= arg1_length-1 && j-1 >= 0)
			{
				//printf("i %d\n",i);
				char temp_arg3[j];
				strncpy(temp_arg3,arg3,j);
				//printf("j %d\n",j-1);
				//printf("arg1 %s \n",arg1+(i+1));
				//printf("arg3 %s \n",temp_arg3);
				if(!strcmp(arg2,"*"))
					temp = atof(arg1+(i+1)) * atof(temp_arg3);
				else if(!strcmp(arg2,"/"))
					temp = atof(arg1+(i+1)) / atof(temp_arg3);
				else if(!strcmp(arg2,"%"))
					temp = atoi(arg1+(i+1)) % atoi(temp_arg3);
				else if(!strcmp(arg2,"+"))
					temp = atof(arg1+(i+1)) + atof(temp_arg3);
				else if(!strcmp(arg2,"-"))
					temp = atof(arg1+(i+1)) - atof(temp_arg3);
				else if(!strcmp(arg2,"<"))
					temp = atof(arg1+(i+1)) < atof(temp_arg3);
				else if(!strcmp(arg2,">"))
					temp = atof(arg1+(i+1)) > atof(temp_arg3);
				else if(!strcmp(arg2,">="))
					temp = atof(arg1+(i+1)) >= atof(temp_arg3);
				else if(!strcmp(arg2,"<="))
					temp = atof(arg1+(i+1)) <= atof(temp_arg3);
				else if(!strcmp(arg2,"!="))
					temp = atof(arg1+(i+1)) != atof(temp_arg3);
				else if(!strcmp(arg2,"=="))
					temp = atof(arg1+(i+1)) == atof(temp_arg3);
				
				char buf[128];
				gcvt(temp,6,buf);
				/*
				if(!strcmp(buf,"inf"))
				{
					printf("Error\n");
					exit(0);
				}
				*/
				//buf[strlen(buf)] = '\0';
				strcat(buf,arg3+j);
				//printf("result %s\n",result);
				//printf("arg1 %s \n",arg1);
				//printf("arg2 %s \n",arg2);
				//printf("arg3 %s \n",arg3);
				//printf("buf %s\n",buf);
				//printf("arg1+i+1 %s\n",arg1+i+1);
				//printf("arg1 %s\n",arg1);
				strncpy(arg1+i+1,buf,sizeof(buf));
				//arg1[strlen(arg1)] = '\0';
				
				//printf("\n");
				strcpy(result,arg1);
				//printf("arg1 %s \n",arg1);
				//printf("result %s \n",result);
				//strcat(result,buf);
				return;
			}
			else
			{
				//printf("in else part of fun function arg1 =  %s arg3 = %s\n",arg1,arg3);
				strncpy(result,arg1,sizeof(arg1));
				strcat(result,arg2);
				//result[strlen(result)] = '\0';
				strcat(result,arg3);
				result[strlen(result)] = '\0';
				//printf("res %s\n",result);
				return;
			}
			//temp = atof(arg1) * atof(arg3);
		}
		/*
		else if(!strcmp(arg2,"/"))
			temp = atof(arg1) / atof(arg3);
		else if(!strcmp(arg2,"%"))
			temp = atoi(arg1) % atoi(arg3);
		else if(!strcmp(arg2,"+"))
			temp = atof(arg1) + atof(arg3);
		else if(!strcmp(arg2,"-"))
			temp = atof(arg1) - atof(arg3);
		else if(!strcmp(arg2,"<"))
			temp = atof(arg1) < atof(arg3);
		else if(!strcmp(arg2,">"))
			temp = atof(arg1) > atof(arg3);
		else if(!strcmp(arg2,"="))
		{
		}
		gcvt(temp,6,result);
		result[strlen(result)] = '\0';
		printf("In Else -> Result for %s * %s : %s\n",arg1,arg3,result);
		*/
	}
	else
	{
		char *p[128];
		strncpy(result,arg1,sizeof(arg1));
		//strcat(result,arg1);
		result[strlen(result)] = '\0';
		//printf("result 1 %s\n",result);
		//printf("arg2 %s\n",arg2);
		//strncpy(result+strlen(result),arg2,2);
		strcat(result,arg2);
		result[strlen(result)] = '\0';
		//printf("result 2 %s \n",result);
		//printf("arg3 %s \n",arg3);
		//strncpy(result+strlen(result),arg3,strlen(arg3));
		strcat(result,arg3);
		result[strlen(result)] = '\0';
		//printf("In If -> Result for %s * %s : %s\n",arg1,arg3,result);
	}	
}

int update_variable_value(char *name,char *value)
{
	int i,j;
	int index_to_insert;
	char *temp_name;
	for(i=top_stack_for_symbol_tables;i>=0;i--)
	{
		index_to_insert = symbol_table_stack[i].index_to_insert;
	//printf("name : %s",name);
		for(j=0;j<index_to_insert;j++)
		{
			temp_name = symbol_table_stack[i].symbol_table[j].name;
			//printf("temp_name : %s",temp_name);
			if(!strcmp(temp_name,name))
			{
				if(strlen(value) == 0)
					return 1;
				value[strlen(value)] = '\0';	// to ensure value string is null terminated
				strcpy(symbol_table_stack[i].symbol_table[j].value,value);
				return 1;
			}
		}
	}
	return -1;	
}

void check(char *arg1,char *arg3)
{
	char temp_name[128];
	int i=0;
	//printf("arg1 : %s arg3 : %s\n",arg1,arg3);
	int flag_operator = 0;	// means argument passed doesn't have operator
	int value;
	if( !isdigit(arg1[0]) && arg1[0] != '(' )
	{
		// for ensuring no operator is present in argument passed. Ex = (p*q-1)	gives arg1 = p*q and arg3 = 1
		while( arg1[i] != '\0' )
		{
			if( !isalnum(arg1[i]) )
			{
				flag_operator = 1;				
				break;
			}
			i++;
		}
		//printf("check flag %d\n",flag_operator);	
		if( !flag_operator )
		{
			// check if varaible in arg1 is present in symbol table or not
			value = update_variable_value(arg1,"");
			if(value == -1)
			{
				not_defined = 1;
				FILE *fptr = fopen("error.txt","a");
				fprintf(fptr,"Varaible %s is not defined\n",arg1);
				error = 1;
				fclose(fptr);
			}
		}
	}
	i=0;
	flag_operator = 0;
	if( !isdigit(arg3[0]) && arg3[0] != '(' )
	{
		while( arg3[i] != '\0' )
		{
			if( !isalnum(arg3[i]) )
			{
				flag_operator = 1;				
				break;
			}
			i++;
		}
		if( !flag_operator )
		{
			//check if varaible in arg1 is present in symbol table or not
			value = update_variable_value(arg3,"");
			if(value == -1)
			{
				not_defined = 1;
				FILE *fptr = fopen("error.txt","a");
				fprintf(fptr,"Varaible %s is not defined\n",arg3);
				error = 1;
				fclose(fptr);
			}
		}
	}
	
}

int add_struct_member_in_symbol_table(char *struct_name)
{
	// to make sure struct_name is null terminated
	//printf("struct name : %s\n",struct_name);
	struct_name[strlen(struct_name)] = '\0';
	
	//int index_to_insert = symbol_table_stack[top_stack_for_symbol_tables].index_to_insert;
	int last_struct_inserted_index = symbol_table_stack[top_stack_for_symbol_tables].struct_index_to_insert - 1;
	
	int last_insert_index_member_struct = symbol_table_stack[top_stack_for_symbol_tables].struct_defined[last_struct_inserted_index].index_to_insert_member;
	
	int j=0,i;	// index for member of struct;
	char *type;
	char *var_name;
	char name[128];
	for(i=0;i<last_insert_index_member_struct;i++)
	{
		type = symbol_table_stack[top_stack_for_symbol_tables].struct_defined[last_struct_inserted_index].member_type[j];
		var_name = symbol_table_stack[top_stack_for_symbol_tables].struct_defined[last_struct_inserted_index].member_name[j];
		strcpy(name,struct_name);
		strcat(name,".");
		strcat(name,var_name);
		name[strlen(name)] = '\0';
		j++;
		push_my(type,name,"",scope);
	}
}

void struct_member(char *type,char *name)
{
	if(scope == NEWSCOPE)
	{
		++top_stack_for_symbol_tables;
		scope = OLDSCOPE;
		//printf("inside struct\n");
	}
	int *struct_index_to_insert = &symbol_table_stack[top_stack_for_symbol_tables].struct_index_to_insert;
	//int *index_to_insert_member = &symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].index_to_insert_member;
	if(strlen(type) != 0 && strlen(name) != 0)
	{
		//printf("Struct member name %s\n",name);
		//printf("Struct member type %s\n",type);
		int *index_to_insert_member;
		if(struct_reference_used == 0 && !strcmp(type,"struct")) 
		{
			//printf("!!!!!!!!!!!!!\n");
			*struct_index_to_insert -= 1;
			symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].struct_name[0] = '\0';
			index_to_insert_member = &symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].index_to_insert_member;
			int i;
			//printf("nested_struct_start_index %d\n",nested_struct_start_index);
			char new_name[2*LIMIT];
			for(i=nested_struct_start_index;i<*index_to_insert_member;i++)
			{
				strcpy(new_name,name);
				strcat(new_name,".");
				strcat(new_name,symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_name[i]);
				//printf("new name %s\n"new_name);
				strcpy(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_name[i],new_name);
				//strcat(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_name[i],".");
				//strcat(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_name[i],name);
			}
			//printf("nested struct name %s\n",symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_name[i-1]);
			//printf("nested struct name %s\n",symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_type[i-1]);
		}
		else
		{
			index_to_insert_member = &symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].index_to_insert_member;
			//printf("struct_index_to_insert %d\n",*struct_index_to_insert);

			//printf("index_to_insert_member %d\n",*index_to_insert_member);
			strcpy(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_type[*index_to_insert_member],type);
			strcpy(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].member_name[*index_to_insert_member],name);
			*index_to_insert_member += 1;
			struct_reference_used = 0;
		}
	}
	else
	{
		//printf("Struct name %s\n",name);
		strcpy(symbol_table_stack[top_stack_for_symbol_tables].struct_defined[*struct_index_to_insert].struct_name,name);
		*struct_index_to_insert += 1;
	}
}
