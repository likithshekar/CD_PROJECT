
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
     ASSIGN = 258,
     GT = 259,
     LT = 260,
     NE = 261,
     EQ = 262,
     GE = 263,
     LE = 264,
     SUB = 265,
     ADD = 266,
     DIV = 267,
     MUL = 268,
     OR = 269,
     AND = 270,
     NOT = 271,
     charconst = 272,
     stringconst = 273,
     MOD = 274,
     SADD = 275,
     SSUB = 276,
     SMUL = 277,
     SDIV = 278,
     SMOD = 279,
     INC = 280,
     DEC = 281,
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
     NL = 298,
     OP = 299,
     CP = 300,
     OB = 301,
     CB = 302,
     OS = 303,
     CS = 304
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


