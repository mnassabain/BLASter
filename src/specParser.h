/* A Bison parser, made by GNU Bison 3.4.2.  */

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

#ifndef YY_ZZ_SPECPARSER_H_INCLUDED
# define YY_ZZ_SPECPARSER_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int zzdebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IDENTIFIER = 258,
    INT_VAL = 259,
    DOUBLE_VAL = 260,
    STRING = 261,
    COMMENT = 262,
    ASSIGN = 263,
    IF = 264,
    WHILE = 265,
    ELSE = 266,
    FOR = 267,
    MACRO = 268,
    MAIN = 269,
    RETURN = 270,
    INT = 271,
    DOUBLE = 272,
    VOID = 273,
    INC = 274,
    DEC = 275,
    PRINTF = 276,
    AND_OP = 277,
    OR_OP = 278,
    GEQ_OP = 279,
    LEQ_OP = 280,
    EQ_OP = 281,
    NEQ_OP = 282,
    UMINUS = 283
  };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INT_VAL 259
#define DOUBLE_VAL 260
#define STRING 261
#define COMMENT 262
#define ASSIGN 263
#define IF 264
#define WHILE 265
#define ELSE 266
#define FOR 267
#define MACRO 268
#define MAIN 269
#define RETURN 270
#define INT 271
#define DOUBLE 272
#define VOID 273
#define INC 274
#define DEC 275
#define PRINTF 276
#define AND_OP 277
#define OR_OP 278
#define GEQ_OP 279
#define LEQ_OP 280
#define EQ_OP 281
#define NEQ_OP 282
#define UMINUS 283

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 17 "specParser.y"

    char* string;
    int int_val;
    double double_val;
    ast specTree;

#line 120 "specParser.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE zzlval;

int zzparse (void);

#endif /* !YY_ZZ_SPECPARSER_H_INCLUDED  */
