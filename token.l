%{
    #include<stdio.h>
    #include<stdlib.h>
    char symbol[100][3];
    int i=0;
%}

letter [a-zA-Z]
digit [0-9]

%%
\n yylineno++;
#include<{letter}+(\.{letter}*)?> printf("%d\t%sPreproccesor\n",yylineno,yytext);
return|main|for|while|case|switch|if|else|elseif|int|float|char|bool printf("%d\t%s\t\tKW\n",yylineno,yytext);
\( printf("%d\t%s\t\tBracket open\n",yylineno,yytext);
\) printf("%d\t%s\t\tBracket close\n",yylineno,yytext);
{letter}({letter}|{digit})* printf("%d\t%s\t\tID\n",yylineno,yytext);
{digit}+ printf("%d\t%s\t\tInteger\n",yylineno,yytext);
\{ printf("%d\t%s\t\tCurly bracket open\n",yylineno,yytext);
\} printf("%d\t%s\t\tCurly bracket close\n",yylineno,yytext);
{digit}+"E"(\+|\-)?{digit}+ printf("%d\t%s\t\tReal number\n",yylineno,yytext);
{digit}+\.{digit}+(E(\+|\-)?{digit}+)? printf("%d\t%s\t\tFloating number\n",yylineno,yytext);
= printf("%d\t%s\t\tAssignment\n",yylineno,yytext);

\>|\<|\>\=|\<\=|\!\=|\=\=|\!|\&\&|\|\| printf("%d\t%s\t\tROP\n",yylineno,yytext);

\+|\-|\*|\/|\%|\+\+|\-\-|\+\=|\-\=|\*\=|\/\=|\%= printf("%d\t%s\t\tAOP\n",yylineno,yytext);

[ ]|; printf("%d\t%s\t\tSEP\n",yylineno,yytext);
\t ;
\/\/.*\n {;}
\/\*(.*\n)*.*\*\/  {;}
\/\*(.*\n)*.*\*\/\n  {;}
\"({letter}|{digit}|" ")*\" printf("%d\t%s\tString\n",yylineno,yytext);
\'({letter}|{digit})\' printf("%d\t%s\tCharacter\n",yylineno,yytext);

%%

int yywrap(){
    return 1;
}

int main(int argc, char * argv[]){
    yyin=fopen(argv[1],"r");
    yyout=fopen(argv[2],"w");
    printf("LINE\tLEXEME\t\tTOKEN\n");
    yylex();
    fclose(yyin);
    return 0;
}
