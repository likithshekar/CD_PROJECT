/* A Bison parser, made by GNU Bison 3.3.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2019 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ASSIGN = 258,
    LE = 259,
    GE = 260,
    EQ = 261,
    NE = 262,
    LT = 263,
    GT = 264,
    ADD = 265,
    SUB = 266,
    MUL = 267,
    DIV = 268,
    AND = 269,
    OR = 270,
    NOT = 271,
    HASH = 272,
    INCLUDE = 273,
    DEFINE = 274,
    STDIO = 275,
    STDLIB = 276,
    MATH = 277,
    STRING = 278,
    TIME = 279,
    STRING_LITERAL = 280,
    HEADER_LITERAL = 281,
    charconst = 282,
    stringconst = 283,
    MOD = 284,
    SADD = 285,
    SSUB = 286,
    SMUL = 287,
    SDIV = 288,
    SMOD = 289,
    INC = 290,
    DEC = 291,
    IF = 292,
    ELSE = 293,
    ELSEIF = 294,
    FOR = 295,
    WHILE = 296,
    BREAK = 297,
    RETURN = 298,
    INT = 299,
    CHAR = 300,
    FLOAT = 301,
    BOOL = 302,
    ID = 303,
    numconst = 304,
    delimiter = 305,
    SEMI = 306,
    COMMA = 307,
    NL = 308,
    OP = 309,
    CP = 310,
    OB = 311,
    CB = 312,
    OS = 313,
    CS = 314
  };
#endif
/* Tokens.  */
#define ASSIGN 258
#define LE 259
#define GE 260
#define EQ 261
#define NE 262
#define LT 263
#define GT 264
#define ADD 265
#define SUB 266
#define MUL 267
#define DIV 268
#define AND 269
#define OR 270
#define NOT 271
#define HASH 272
#define INCLUDE 273
#define DEFINE 274
#define STDIO 275
#define STDLIB 276
#define MATH 277
#define STRING 278
#define TIME 279
#define STRING_LITERAL 280
#define HEADER_LITERAL 281
#define charconst 282
#define stringconst 283
#define MOD 284
#define SADD 285
#define SSUB 286
#define SMUL 287
#define SDIV 288
#define SMOD 289
#define INC 290
#define DEC 291
#define IF 292
#define ELSE 293
#define ELSEIF 294
#define FOR 295
#define WHILE 296
#define BREAK 297
#define RETURN 298
#define INT 299
#define CHAR 300
#define FLOAT 301
#define BOOL 302
#define ID 303
#define numconst 304
#define delimiter 305
#define SEMI 306
#define COMMA 307
#define NL 308
#define OP 309
#define CP 310
#define OB 311
#define CB 312
#define OS 313
#define CS 314

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 113 "c_yacc.y" /* yacc.c:1921  */

	int ival;
	char string[128];

#line 181 "y.tab.h" /* yacc.c:1921  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
