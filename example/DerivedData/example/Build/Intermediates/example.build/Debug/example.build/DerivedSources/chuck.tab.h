/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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
     ID = 258,
     STRING_LIT = 259,
     CHAR_LIT = 260,
     NUM = 261,
     FLOAT = 262,
     POUND = 263,
     COMMA = 264,
     COLON = 265,
     SEMICOLON = 266,
     LPAREN = 267,
     RPAREN = 268,
     LBRACK = 269,
     RBRACK = 270,
     LBRACE = 271,
     RBRACE = 272,
     DOT = 273,
     PLUS = 274,
     MINUS = 275,
     TIMES = 276,
     DIVIDE = 277,
     PERCENT = 278,
     EQ = 279,
     NEQ = 280,
     LT = 281,
     LE = 282,
     GT = 283,
     GE = 284,
     AND = 285,
     OR = 286,
     ASSIGN = 287,
     IF = 288,
     THEN = 289,
     ELSE = 290,
     WHILE = 291,
     FOR = 292,
     DO = 293,
     LOOP = 294,
     BREAK = 295,
     CONTINUE = 296,
     NULL_TOK = 297,
     FUNCTION = 298,
     RETURN = 299,
     QUESTION = 300,
     EXCLAMATION = 301,
     S_OR = 302,
     S_AND = 303,
     S_XOR = 304,
     PLUSPLUS = 305,
     MINUSMINUS = 306,
     DOLLAR = 307,
     POUNDPAREN = 308,
     PERCENTPAREN = 309,
     ATPAREN = 310,
     SIMULT = 311,
     PATTERN = 312,
     CODE = 313,
     TRANSPORT = 314,
     HOST = 315,
     TIME = 316,
     WHENEVER = 317,
     NEXT = 318,
     UNTIL = 319,
     EVERY = 320,
     BEFORE = 321,
     AFTER = 322,
     AT = 323,
     AT_SYM = 324,
     ATAT_SYM = 325,
     NEW = 326,
     SIZEOF = 327,
     TYPEOF = 328,
     SAME = 329,
     PLUS_CHUCK = 330,
     MINUS_CHUCK = 331,
     TIMES_CHUCK = 332,
     DIVIDE_CHUCK = 333,
     S_AND_CHUCK = 334,
     S_OR_CHUCK = 335,
     S_XOR_CHUCK = 336,
     SHIFT_RIGHT_CHUCK = 337,
     SHIFT_LEFT_CHUCK = 338,
     PERCENT_CHUCK = 339,
     SHIFT_RIGHT = 340,
     SHIFT_LEFT = 341,
     TILDA = 342,
     CHUCK = 343,
     COLONCOLON = 344,
     S_CHUCK = 345,
     AT_CHUCK = 346,
     LEFT_S_CHUCK = 347,
     UNCHUCK = 348,
     UPCHUCK = 349,
     CLASS = 350,
     INTERFACE = 351,
     EXTENDS = 352,
     IMPLEMENTS = 353,
     PUBLIC = 354,
     PROTECTED = 355,
     PRIVATE = 356,
     STATIC = 357,
     ABSTRACT = 358,
     CONST = 359,
     SPORK = 360,
     ARROW_RIGHT = 361,
     ARROW_LEFT = 362,
     L_HACK = 363,
     R_HACK = 364
   };
#endif
/* Tokens.  */
#define ID 258
#define STRING_LIT 259
#define CHAR_LIT 260
#define NUM 261
#define FLOAT 262
#define POUND 263
#define COMMA 264
#define COLON 265
#define SEMICOLON 266
#define LPAREN 267
#define RPAREN 268
#define LBRACK 269
#define RBRACK 270
#define LBRACE 271
#define RBRACE 272
#define DOT 273
#define PLUS 274
#define MINUS 275
#define TIMES 276
#define DIVIDE 277
#define PERCENT 278
#define EQ 279
#define NEQ 280
#define LT 281
#define LE 282
#define GT 283
#define GE 284
#define AND 285
#define OR 286
#define ASSIGN 287
#define IF 288
#define THEN 289
#define ELSE 290
#define WHILE 291
#define FOR 292
#define DO 293
#define LOOP 294
#define BREAK 295
#define CONTINUE 296
#define NULL_TOK 297
#define FUNCTION 298
#define RETURN 299
#define QUESTION 300
#define EXCLAMATION 301
#define S_OR 302
#define S_AND 303
#define S_XOR 304
#define PLUSPLUS 305
#define MINUSMINUS 306
#define DOLLAR 307
#define POUNDPAREN 308
#define PERCENTPAREN 309
#define ATPAREN 310
#define SIMULT 311
#define PATTERN 312
#define CODE 313
#define TRANSPORT 314
#define HOST 315
#define TIME 316
#define WHENEVER 317
#define NEXT 318
#define UNTIL 319
#define EVERY 320
#define BEFORE 321
#define AFTER 322
#define AT 323
#define AT_SYM 324
#define ATAT_SYM 325
#define NEW 326
#define SIZEOF 327
#define TYPEOF 328
#define SAME 329
#define PLUS_CHUCK 330
#define MINUS_CHUCK 331
#define TIMES_CHUCK 332
#define DIVIDE_CHUCK 333
#define S_AND_CHUCK 334
#define S_OR_CHUCK 335
#define S_XOR_CHUCK 336
#define SHIFT_RIGHT_CHUCK 337
#define SHIFT_LEFT_CHUCK 338
#define PERCENT_CHUCK 339
#define SHIFT_RIGHT 340
#define SHIFT_LEFT 341
#define TILDA 342
#define CHUCK 343
#define COLONCOLON 344
#define S_CHUCK 345
#define AT_CHUCK 346
#define LEFT_S_CHUCK 347
#define UNCHUCK 348
#define UPCHUCK 349
#define CLASS 350
#define INTERFACE 351
#define EXTENDS 352
#define IMPLEMENTS 353
#define PUBLIC 354
#define PROTECTED 355
#define PRIVATE 356
#define STATIC 357
#define ABSTRACT 358
#define CONST 359
#define SPORK 360
#define ARROW_RIGHT 361
#define ARROW_LEFT 362
#define L_HACK 363
#define R_HACK 364




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 59 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/libs/chuck/chuck.y"
{
    int pos;
    int ival;
    double fval;
    c_str sval;
    
    a_Program program;
    a_Section program_section;
    a_Stmt_List stmt_list;
    a_Class_Def class_def;
    a_Class_Ext class_ext;
    a_Class_Body class_body;
    a_Stmt stmt;
    a_Exp exp;
    a_Func_Def func_def;
    a_Var_Decl_List var_decl_list;
    a_Var_Decl var_decl;
    a_Type_Decl type_decl;
    a_Arg_List arg_list;
    a_Id_List id_list;
    a_Array_Sub array_sub;
    a_Complex complex_exp;
    a_Polar polar_exp;
    a_Vec vec_exp; // ge: added 1.3.5.3
}
/* Line 1529 of yacc.c.  */
#line 293 "/Users/slork/Desktop/of_v0.8.4_osx_release/addons/ofxChucK/example/DerivedData/example/Build/Intermediates/example.build/Debug/example.build/DerivedSources/chuck.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

