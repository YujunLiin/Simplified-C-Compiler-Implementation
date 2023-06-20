/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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

#ifndef YY_YY_SRC_MAIN_TAB_H_INCLUDED
# define YY_YY_SRC_MAIN_TAB_H_INCLUDED
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
    T_CHAR = 258,
    T_INT = 259,
    T_STRING = 260,
    T_BOOL = 261,
    T_VOID = 262,
    IF = 263,
    MAIN = 264,
    ELSE = 265,
    FOR = 266,
    WHILE = 267,
    PRINTF = 268,
    SCANF = 269,
    BREAK = 270,
    CONTINUE = 271,
    RETURN = 272,
    LBRACE = 273,
    RBRACE = 274,
    SEMI = 275,
    PLUS = 276,
    MINUS = 277,
    TIMES = 278,
    OVER = 279,
    ASSIGN = 280,
    INC = 281,
    DEC = 282,
    MOD = 283,
    LT = 284,
    EQ = 285,
    GT = 286,
    NZ = 287,
    GE = 288,
    LE = 289,
    SHL = 290,
    SAR = 291,
    AND = 292,
    OR = 293,
    OPPSITE = 294,
    LPAREN = 295,
    RPAREN = 296,
    COMMA = 297,
    LSQUARE = 298,
    RSQUARE = 299,
    B_AND = 300,
    IDENTIFIER = 301,
    INTEGER = 302,
    CHAR = 303,
    BOOL = 304,
    STRING = 305,
    CONST = 306,
    OPPOSITE = 307
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_MAIN_TAB_H_INCLUDED  */
