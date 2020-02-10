
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     charconst = 258,
     stringconst = 259,
     SUB = 260,
     ADD = 261,
     MUL = 262,
     DIV = 263,
     MOD = 264,
     SADD = 265,
     SSUB = 266,
     SMUL = 267,
     SDIV = 268,
     SMOD = 269,
     INC = 270,
     DEC = 271,
     GT = 272,
     LT = 273,
     NE = 274,
     GE = 275,
     LE = 276,
     EQ = 277,
     ASSIGN = 278,
     AND = 279,
     OR = 280,
     NOT = 281,
     IF = 282,
     ELSE = 283,
     ELSEIF = 284,
     FOR = 285,
     WHILE = 286,
     BREAK = 287,
     RETURN = 288,
     INT = 289,
     CHAR = 290,
     FLOAT = 291,
     BOOL = 292,
     ID = 293,
     numconst = 294,
     delimiter = 295,
     SEMI = 296,
     COMMA = 297,
     OP = 298,
     CP = 299,
     OB = 300,
     CB = 301,
     OS = 302,
     CS = 303
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


